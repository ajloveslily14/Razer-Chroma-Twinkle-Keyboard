#include "twinkle.h"

#ifdef _WIN64
#define CHROMASDKDLL        "RzChromaSDK64.dll"
#else
#define CHROMASDKDLL        "RzChromaSDK.dll"
#endif



typedef RZRESULT(*INIT)();
typedef RZRESULT(*CREATEEFFECT)(RZDEVICEID DeviceID, ChromaSDK::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId);
typedef RZRESULT(*CREATEKEYBOARDEFFECT)(ChromaSDK::Keyboard::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId);
INIT Init = nullptr;
CREATEEFFECT CreateEffect = nullptr;
CREATEKEYBOARDEFFECT CreateKeyboardEffect = nullptr;



ChromaClass::ChromaClass():m_ChromaSDKModule(nullptr) {

}

BOOL ChromaClass::Initialize() {
	if (m_ChromaSDKModule == nullptr) {
		m_ChromaSDKModule = ::LoadLibrary(CHROMASDKDLL);
		if (m_ChromaSDKModule == nullptr) {
			return false;
		}
	}
	if (Init == nullptr) {
		auto Res = RZRESULT_INVALID;
		Init = (INIT)::GetProcAddress(m_ChromaSDKModule,"Init");
		if (Init) {
			Res = Init();
			if (Res == RZRESULT_SUCCESS){
			CreateEffect = (CREATEEFFECT)::GetProcAddress(m_ChromaSDKModule, "CreateEffect");
			CreateKeyboardEffect = (CREATEKEYBOARDEFFECT)::GetProcAddress(m_ChromaSDKModule, "CreateKeyboardEffect");
			if (CreateEffect && CreateKeyboardEffect) {
				return true;
			} else {
				return false;
			}
		}
		}
		
	}
	return true;
}

struct star {
	int row;
	int col;
	COLORREF color;
	float life;

};
std::vector<star> stars;




int hueIndex = 0;
void ChromaClass::DoColors() {
	ChromaSDK::Keyboard::CUSTOM_EFFECT_TYPE kb = {};

	hsv colorHSV = {};
	colorHSV.h = hueIndex;
	colorHSV.s = 1;
	colorHSV.v = 1;
	rgb colorRGB = hsv2rgb(colorHSV);
	COLORREF color = RGB(colorRGB.r*255,colorRGB.g*255,colorRGB.b*255);
	for (size_t row = 0; row < ChromaSDK::Keyboard::MAX_ROW; row++) {
		for (size_t col = 0; col < ChromaSDK::Keyboard::MAX_COLUMN; col++) {
			kb.Color[row][col] = color;
		}
	}
	
	int randX = rand() % ChromaSDK::Keyboard::MAX_ROW;
	int randY = rand() % ChromaSDK::Keyboard::MAX_COLUMN;
	star newStar;

	newStar.row = randX;
	newStar.col = randY;
	newStar.color = randColor();
	newStar.life = 1.0f;
	stars.push_back(newStar);

	for (auto si = stars.begin(); si != stars.end();) {
		COLORREF dimmedColor = adjustBrightness(si->color,si->life);
		kb.Color[si->row][si->col] = dimmedColor;
		si->life -= 0.05f;
		if (si->life <= 0.0f){
			si = stars.erase(si);
		} else {
			++si;
		}
	}

	CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_CUSTOM,&kb,nullptr);
	hueIndex++;
	hueIndex %= 361;


}


int main(int argc, char const *argv[])
{
	std::cout << "Attempting to initialize..." << std::flush;

	ChromaClass chromacontroller;
	bool test_init = chromacontroller.Initialize();
	if (test_init == true) {
		std::cout << "done!" << std::flush;
		Sleep(1000);
		while ( true ) {
			chromacontroller.DoColors();
			Sleep(50);
		}
	}
	return 0;
}