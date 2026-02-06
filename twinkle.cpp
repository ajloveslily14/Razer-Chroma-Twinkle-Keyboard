#include "twinkle.h"

#ifdef _WIN64
#define CHROMASDKDLL        "RzChromaSDK64.dll"
#else
#define CHROMASDKDLL        "RzChromaSDK.dll"
#endif



typedef RZRESULT(*INIT)();
typedef RZRESULT(*CREATEKEYBOARDEFFECT)(ChromaSDK::Keyboard::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId);
INIT Init = nullptr;
CREATEKEYBOARDEFFECT CreateKeyboardEffect = nullptr;



ChromaClass::ChromaClass():m_ChromaSDKModule(nullptr) {

}

BOOL ChromaClass::Initialize() {
	if (m_ChromaSDKModule == nullptr) {
		m_ChromaSDKModule = ::LoadLibrary(CHROMASDKDLL); // Load the razer chroma SDK DLL
		if (m_ChromaSDKModule == nullptr) {
			return false;
		}
	}
	if (Init == nullptr) {
		auto Res = RZRESULT_INVALID;
		Init = (INIT)::GetProcAddress(m_ChromaSDKModule,"Init"); // The documentation says this should be InitSDK but that'll crash if you try and set effects with it
		if (Init) {
			Res = Init();
			if (Res == RZRESULT_SUCCESS){

			CreateKeyboardEffect = (CREATEKEYBOARDEFFECT)::GetProcAddress(m_ChromaSDKModule, "CreateKeyboardEffect");
			if (CreateKeyboardEffect) {
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
void ChromaClass::DoColors() { // This is our main effect loop
	ChromaSDK::Keyboard::CUSTOM_EFFECT_TYPE kb = {}; // This initializes our custom keyboard effect which is a 2d maxtix based effect

	hsv colorHSV = {};
	colorHSV.h = hueIndex;
	colorHSV.s = 1;
	colorHSV.v = 1;
	rgb colorRGB = hsv2rgb(colorHSV);
	COLORREF color = RGB(colorRGB.r*255,colorRGB.g*255,colorRGB.b*255);
	for (size_t row = 0; row < ChromaSDK::Keyboard::MAX_ROW; row++) {
		for (size_t col = 0; col < ChromaSDK::Keyboard::MAX_COLUMN; col++) {
			kb.Color[row][col] = color; // flood the whole keyboard with color
		}
	}
	
	int randX = rand() % ChromaSDK::Keyboard::MAX_ROW;
	int randY = rand() % ChromaSDK::Keyboard::MAX_COLUMN;
	star newStar; // Intialize a new "star" to be rendered

	newStar.row = randX;
	newStar.col = randY;
	newStar.color = randColor();
	newStar.life = 1.0f;
	stars.push_back(newStar);

	for (auto si = stars.begin(); si != stars.end();) { // Process "stars"
		COLORREF dimmedColor = adjustBrightness(si->color,si->life); // Get our "dimmed" star color value
		kb.Color[si->row][si->col] = dimmedColor; // Actually apply the star color
		si->life -= 0.05f; // Decrement our star life 
		if (si->life <= 0.0f){
			si = stars.erase(si); // Remove our star if it's dead
		} else {
			++si;
		}
	}

	CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_CUSTOM,&kb,nullptr); // This creates and applies the keyboard effect we defined
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