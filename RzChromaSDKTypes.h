#ifndef _RZCHROMASDKTYPES_H_
#define _RZCHROMASDKTYPES_H_
 
#pragma once
 
typedef LONG            RZRESULT;           
typedef GUID            RZEFFECTID;         
typedef GUID            RZDEVICEID;         
typedef unsigned int    RZDURATION;         
typedef size_t          RZSIZE;             
typedef void*           PRZPARAM;           
typedef DWORD           RZID;               
typedef DWORD           RZCOLOR;            
 
 
namespace ChromaSDK
{
    const UINT WM_CHROMA_EVENT = WM_APP + 0x2000;
 
    typedef struct APPINFOTYPE
    {
        TCHAR Title[256];           
        TCHAR Description[1024];    
        struct Author
        {
            TCHAR Name[256];        
            TCHAR Contact[256];     
        } Author;
        DWORD SupportedDevice;      
        DWORD Category;             
    } APPINFOTYPE;
 
    typedef enum EFFECT_TYPE
    {
        CHROMA_NONE = 0,            
        CHROMA_WAVE,                // Wave effect (Deprecated and should not be used).
        CHROMA_SPECTRUMCYCLING,     // Spectrum cycling effect (Deprecated and should not be used).
        CHROMA_BREATHING,           // Breathing effect (Deprecated and should not be used).
        CHROMA_BLINKING,            // Blinking effect (Deprecated and should not be used).
        CHROMA_REACTIVE,            // Reactive effect (Deprecated and should not be used).
        CHROMA_STATIC,              
        CHROMA_CUSTOM,              
        CHROMA_CUSTOM2,             
        CHROMA_RESERVED,            
        CHROMA_INVALID              
    } EFFECT_TYPE;
 
    typedef struct DEVICE_INFO_TYPE
    {
        enum DeviceType
        {
            DEVICE_KEYBOARD = 1, 
            DEVICE_MOUSE = 2, 
            DEVICE_HEADSET = 3, 
            DEVICE_MOUSEPAD = 4, 
            DEVICE_KEYPAD = 5, 
            DEVICE_SYSTEM = 6, 
            DEVICE_SPEAKERS = 7, 
            DEVICE_INVALID          
        } DeviceType;
 
        DWORD Connected;            
    } DEVICE_INFO_TYPE;
 
    const RZSIZE MAX_ROW = 30;      
    const RZSIZE MAX_COLUMN = 30;   
 
    typedef struct EFFECT_HEADER_TYPE
    {
        RZSIZE Size;
        DWORD Param;
    } EFFECT_HEADER_TYPE, *PEFFECT_HEADER_TYPE;
 
    typedef struct EFFECT_DATA_TYPE
    {
        EFFECT_HEADER_TYPE Header;
        PRZPARAM pData;
    } EFFECT_DATA_TYPE, *PEFFECT_DATA_TYPE;
 
    // Blinking effect (Deprecated and should not be used).
    typedef struct BLINKING_EFFECT_TYPE
    {
        RZSIZE Size;        // Size of the structure. Size = sizeof(BLINKING_EFFECT_TYPE)
        DWORD Param;        // Extra parameters.
 
        RZCOLOR Color;     // Blinking color
    } BLINKING_EFFECT_TYPE;
 
    // Breathing effect (Deprecated and should not be used).
    typedef struct BREATHING_EFFECT_TYPE
    {
        RZSIZE Size;        // Size of ths structure. Size = sizeof(BREATHING_EFFECT_TYPE)
        DWORD Param;        // Extra parameters.
 
        // Breathing effect types.
        enum _Type
        {
            ONE_COLOR = 1,  // 1 color (Only fill Color1).
            TWO_COLORS,     // 2 colors.
            RANDOM_COLORS   // Random colors
        } Type;
 
        RZCOLOR Color1;    // First color.
        RZCOLOR Color2;    // Second color.
    } BREATHING_EFFECT_TYPE;
 
    typedef struct CUSTOM_EFFECT_TYPE
    {
        RZSIZE Size;        
        DWORD Param;        
 
        RZCOLOR Color[MAX_ROW][MAX_COLUMN]; 
    } CUSTOM_EFFECT_TYPE;
 
    typedef struct NO_EFFECT_TYPE
    {
        RZSIZE Size;        
        DWORD Param;        
    } NO_EFFECT_TYPE;
 
    // Reactive effect (Deprecated and should not be used).
    typedef struct REACTIVE_EFFECT_TYPE
    {
        RZSIZE Size;        // Size of the structure. Size = sizeof(REACTIVE_EFFECT_TYPE)
        DWORD Param;        // Extra parameters.
 
        // Duration of the effect.
        enum _Duration
        {
            DURATION_SHORT = 1, // Short duration.
            DURATION_MEDIUM,    // Medium duration.
            DURATION_LONG       // Long duration.
        } Duration;             // The time taken for the effect to fade away.
 
        RZCOLOR Color;         // Color of the effect.
    } REACTIVE_EFFECT_TYPE;
 
    // Spectrum cycling effect (Deprecated and should not be used).
    typedef struct SPECTRUMCYCLING_EFFECT_TYPE
    {
        RZSIZE Size;        // Size of the structure. Size = sizeof(SPECTRUMCYCLING_EFFECT_TYPE)
        DWORD Param;        // Extra parameters.
    } SPECTRUMCYCLING_EFFECT_TYPE;
 
    // Starlight effect (Deprecated and should not be used).
    typedef struct STARLIGHT_EFFECT_TYPE
    {
        RZSIZE Size;        // Size of the structure. Size = sizeof(SPECTRUMCYCLING_EFFECT_TYPE)
        DWORD Param;        // Extra parameters.
 
        // Starlight effect types.
        enum _Type
        {
            TWO_COLORS = 1, // 2 colors.
            RANDOM_COLORS   // Random colors
        } Type;
 
        RZCOLOR Color1;    // First color.
        RZCOLOR Color2;    // Second color.
 
        // Duration of the effect.
        enum _Duration
        {
            DURATION_SHORT = 1, // Short duration.
            DURATION_MEDIUM,    // Medium duration.
            DURATION_LONG       // Long duration.
        } Duration;             // The time taken for the effect to fade away.
 
    } STARLIGHT_EFFECT_TYPE;
 
    typedef struct STATIC_EFFECT_TYPE
    {
        RZSIZE Size;        
        DWORD Param;        
 
        RZCOLOR Color;     
    } STATIC_EFFECT_TYPE;
 
    // Wave effect (Deprecated and should not be used).
    typedef struct WAVE_EFFECT_TYPE
    {
        RZSIZE Size;        // Size of the structure. Size = sizeof(WAVE_EFFECT_TYPE)
        DWORD Param;        // Extra parameters.
 
        // Direction of effect.
        enum _Direction
        {
            DIRECTION_LEFT_TO_RIGHT = 1,    // Left to right.
            DIRECTION_RIGHT_TO_LEFT,        // Right to left.
            DIRECTION_FRONT_TO_BACK,        // Front to back
            DIRECTION_BACK_TO_FRONT         // Back top front
        } Direction;
    } WAVE_EFFECT_TYPE;
 
    namespace Keyboard
    {
        typedef enum RZKEY
        {
            RZKEY_ESC = 0x0001,                 
            RZKEY_F1 = 0x0003,                  
            RZKEY_F2 = 0x0004,                  
            RZKEY_F3 = 0x0005,                  
            RZKEY_F4 = 0x0006,                  
            RZKEY_F5 = 0x0007,                  
            RZKEY_F6 = 0x0008,                  
            RZKEY_F7 = 0x0009,                  
            RZKEY_F8 = 0x000A,                  
            RZKEY_F9 = 0x000B,                  
            RZKEY_F10 = 0x000C,                 
            RZKEY_F11 = 0x000D,                 
            RZKEY_F12 = 0x000E,                 
            RZKEY_1 = 0x0102,                   
            RZKEY_2 = 0x0103,                   
            RZKEY_3 = 0x0104,                   
            RZKEY_4 = 0x0105,                   
            RZKEY_5 = 0x0106,                   
            RZKEY_6 = 0x0107,                   
            RZKEY_7 = 0x0108,                   
            RZKEY_8 = 0x0109,                   
            RZKEY_9 = 0x010A,                   
            RZKEY_0 = 0x010B,                   
            RZKEY_A = 0x0302,                   
            RZKEY_B = 0x0407,                   
            RZKEY_C = 0x0405,                   
            RZKEY_D = 0x0304,                   
            RZKEY_E = 0x0204,                   
            RZKEY_F = 0x0305,                   
            RZKEY_G = 0x0306,                   
            RZKEY_H = 0x0307,                   
            RZKEY_I = 0x0209,                   
            RZKEY_J = 0x0308,                   
            RZKEY_K = 0x0309,                   
            RZKEY_L = 0x030A,                   
            RZKEY_M = 0x0409,                   
            RZKEY_N = 0x0408,                   
            RZKEY_O = 0x020A,                   
            RZKEY_P = 0x020B,                   
            RZKEY_Q = 0x0202,                   
            RZKEY_R = 0x0205,                   
            RZKEY_S = 0x0303,                   
            RZKEY_T = 0x0206,                   
            RZKEY_U = 0x0208,                   
            RZKEY_V = 0x0406,                   
            RZKEY_W = 0x0203,                   
            RZKEY_X = 0x0404,                   
            RZKEY_Y = 0x0207,                   
            RZKEY_Z = 0x0403,                   
            RZKEY_NUMLOCK = 0x0112,             
            RZKEY_NUMPAD0 = 0x0513,             
            RZKEY_NUMPAD1 = 0x0412,             
            RZKEY_NUMPAD2 = 0x0413,             
            RZKEY_NUMPAD3 = 0x0414,             
            RZKEY_NUMPAD4 = 0x0312,             
            RZKEY_NUMPAD5 = 0x0313,             
            RZKEY_NUMPAD6 = 0x0314,             
            RZKEY_NUMPAD7 = 0x0212,             
            RZKEY_NUMPAD8 = 0x0213,             
            RZKEY_NUMPAD9 = 0x0214,             
            RZKEY_NUMPAD_DIVIDE = 0x0113,       
            RZKEY_NUMPAD_MULTIPLY = 0x0114,     
            RZKEY_NUMPAD_SUBTRACT = 0x0115,     
            RZKEY_NUMPAD_ADD = 0x0215,          
            RZKEY_NUMPAD_ENTER = 0x0415,        
            RZKEY_NUMPAD_DECIMAL = 0x0514,      
            RZKEY_PRINTSCREEN = 0x000F,         
            RZKEY_SCROLL = 0x0010,              
            RZKEY_PAUSE = 0x0011,               
            RZKEY_INSERT = 0x010F,              
            RZKEY_HOME = 0x0110,                
            RZKEY_PAGEUP = 0x0111,              
            RZKEY_DELETE = 0x020f,              
            RZKEY_END = 0x0210,                 
            RZKEY_PAGEDOWN = 0x0211,            
            RZKEY_UP = 0x0410,                  
            RZKEY_LEFT = 0x050F,                
            RZKEY_DOWN = 0x0510,                
            RZKEY_RIGHT = 0x0511,               
            RZKEY_TAB = 0x0201,                 
            RZKEY_CAPSLOCK = 0x0301,            
            RZKEY_BACKSPACE = 0x010E,           
            RZKEY_ENTER = 0x030E,               
            RZKEY_LCTRL = 0x0501,               
            RZKEY_LWIN = 0x0502,                
            RZKEY_LALT = 0x0503,                
            RZKEY_SPACE = 0x0507,               
            RZKEY_RALT = 0x050B,                
            RZKEY_FN = 0x050C,                  
            RZKEY_RMENU = 0x050D,               
            RZKEY_RCTRL = 0x050E,               
            RZKEY_LSHIFT = 0x0401,              
            RZKEY_RSHIFT = 0x040E,              
            RZKEY_MACRO1 = 0x0100,              
            RZKEY_MACRO2 = 0x0200,              
            RZKEY_MACRO3 = 0x0300,              
            RZKEY_MACRO4 = 0x0400,              
            RZKEY_MACRO5 = 0x0500,              
            RZKEY_OEM_1 = 0x0101,               
            RZKEY_OEM_2 = 0x010C,               
            RZKEY_OEM_3 = 0x010D,               
            RZKEY_OEM_4 = 0x020C,               
            RZKEY_OEM_5 = 0x020D,               
            RZKEY_OEM_6 = 0x020E,               
            RZKEY_OEM_7 = 0x030B,               
            RZKEY_OEM_8 = 0x030C,               
            RZKEY_OEM_9 = 0x040A,               
            RZKEY_OEM_10 = 0x040B,              
            RZKEY_OEM_11 = 0x040C,              
            RZKEY_EUR_1 = 0x030D,               
            RZKEY_EUR_2 = 0x0402,               
            RZKEY_JPN_1 = 0x0015,               
            RZKEY_JPN_2 = 0x040D,               
            RZKEY_JPN_3 = 0x0504,               
            RZKEY_JPN_4 = 0x0509,               
            RZKEY_JPN_5 = 0x050A,               
            RZKEY_KOR_1 = 0x0015,               
            RZKEY_KOR_2 = 0x030D,               
            RZKEY_KOR_3 = 0x0402,               
            RZKEY_KOR_4 = 0x040D,               
            RZKEY_KOR_5 = 0x0504,               
            RZKEY_KOR_6 = 0x0509,               
            RZKEY_KOR_7 = 0x050A,               
            RZKEY_INVALID = 0xFFFF              
        } RZKEY;
 
        typedef enum RZLED
        {
            RZLED_LOGO = 0x0014                 
        } RZLED;
 
        const RZSIZE MAX_ROW = 6;
 
        const RZSIZE MAX_COLUMN = 22;
 
        const RZSIZE MAX_KEYS = MAX_ROW * MAX_COLUMN;
 
        const RZSIZE MAX_CUSTOM_EFFECTS = MAX_KEYS;
 
        const RZCOLOR RZKEY_LAYOUT[MAX_ROW][MAX_COLUMN] = {};
 
        typedef enum EFFECT_TYPE
        {
            CHROMA_NONE = 0,            
            CHROMA_BREATHING,           // Breathing effect (Deprecated and should not be used).
            CHROMA_CUSTOM,              
            CHROMA_REACTIVE,            // Reactive effect (Deprecated and should not be used).
            CHROMA_STATIC,              
            CHROMA_SPECTRUMCYCLING,     // Spectrum cycling effect (Deprecated and should not be used).
            CHROMA_WAVE,                // Wave effect (Deprecated and should not be used).
            CHROMA_RESERVED,            
            CHROMA_CUSTOM_KEY,          
            CHROMA_CUSTOM2,             
            CHROMA_INVALID              
        } EFFECT_TYPE;
 
        // Chroma keyboard effects
        // Breathing effect (Deprecated and should not be used).
        typedef struct BREATHING_EFFECT_TYPE
        {
            // Breathing effects.
            enum Type
            {
                TWO_COLORS = 1,     // 2 colors
                RANDOM_COLORS,      // Random colors
                INVALID             // Invalid type
            } Type;
            RZCOLOR Color1;        // First color.
            RZCOLOR Color2;        // Second color.
        } BREATHING_EFFECT_TYPE;
 
        typedef struct CUSTOM_EFFECT_TYPE
        {
            RZCOLOR Color[MAX_ROW][MAX_COLUMN];      
        } CUSTOM_EFFECT_TYPE;
 
        typedef struct CUSTOM_KEY_EFFECT_TYPE
        {
            RZCOLOR Color[MAX_ROW][MAX_COLUMN];        
            RZCOLOR Key[MAX_ROW][MAX_COLUMN];          
        } CUSTOM_KEY_EFFECT_TYPE;
 
        // Reactive effect (Deprecated and should not be used).
        typedef struct REACTIVE_EFFECT_TYPE
        {
            // Duration of the effect.
            enum Duration
            {
                DURATION_NONE = 0,  // No duration.
                DURATION_SHORT,     // Short duration.
                DURATION_MEDIUM,    // Medium duration.
                DURATION_LONG,      // Long duration.
                DURATION_INVALID    // Invalid duration.
            } Duration;             // The time taken for the effect to fade away.
 
            RZCOLOR Color;         // Color of the effect
        } REACTIVE_EFFECT_TYPE;
 
        // Starlight effect (Deprecated and should not be used).
        typedef struct STARLIGHT_EFFECT_TYPE
        {
            // Starlight effect types.
            enum _Type
            {
                TWO_COLORS = 1, // 2 colors.
                RANDOM_COLORS   // Random colors
            } Type;
 
            RZCOLOR Color1;    // First color.
            RZCOLOR Color2;    // Second color.
 
            // Duration of the effect.
            enum _Duration
            {
                DURATION_SHORT = 1, // Short duration.
                DURATION_MEDIUM,    // Medium duration.
                DURATION_LONG       // Long duration.
            } Duration;             // The time taken for the effect to fade away.
 
        } STARLIGHT_EFFECT_TYPE;
 
        typedef struct STATIC_EFFECT_TYPE
        {
            RZCOLOR Color;     
        } STATIC_EFFECT_TYPE;
 
        // Wave effect (Deprecated and should not be used).
        typedef struct WAVE_EFFECT_TYPE
        {
            // Direction of the wave effect.
            enum Direction
            {
                DIRECTION_NONE = 0,         // No direction.
                DIRECTION_LEFT_TO_RIGHT,    // Left to right.
                DIRECTION_RIGHT_TO_LEFT,    // Right to left.
                DIRECTION_INVALID           // Invalid direction.
            } Direction;                    // Direction of the wave.
        } WAVE_EFFECT_TYPE;
 
        namespace v2
        {
            const RZSIZE MAX_ROW = 8;
 
            const RZSIZE MAX_COLUMN = 24;
 
            typedef struct CUSTOM_EFFECT_TYPE
            {
                RZCOLOR Color[MAX_ROW][MAX_COLUMN];                    
                RZCOLOR Key[Keyboard::MAX_ROW][Keyboard::MAX_COLUMN];  
            } CUSTOM_EFFECT_TYPE;
        }
    }
 
    namespace Mouse
    {
        const RZSIZE MAX_LEDS = 30;
 
        const RZCOLOR RZLED_LAYOUT[MAX_LEDS] = {};
 
        const RZSIZE MAX_ROW = 9;
 
        const RZSIZE MAX_COLUMN = 7;
 
        const RZSIZE MAX_LEDS2 = MAX_ROW * MAX_COLUMN;
 
        const RZCOLOR RZLED_LAYOUT2[MAX_ROW][MAX_COLUMN] = {};
 
        // Mouse LED Id defintion (Deprecated and should not be used).
        typedef enum RZLED
        {
            RZLED_NONE = 0,             // No LED.
            RZLED_SCROLLWHEEL = 1,      // Scroll Wheel LED.
            RZLED_LOGO = 2,             // Logo LED.
            RZLED_BACKLIGHT = 3,        // Backlight or numpad.
            RZLED_SIDE_STRIP1 = 4,      // Side strip LED 1. (For Mamba TE, starts from top left hand)
            RZLED_SIDE_STRIP2 = 5,      // Side strip LED 2. (For Mamba TE)
            RZLED_SIDE_STRIP3 = 6,      // Side strip LED 3. (For Mamba TE)
            RZLED_SIDE_STRIP4 = 7,      // Side strip LED 4. (For Mamba TE)
            RZLED_SIDE_STRIP5 = 8,      // Side strip LED 5. (For Mamba TE)
            RZLED_SIDE_STRIP6 = 9,      // Side strip LED 6. (For Mamba TE)
            RZLED_SIDE_STRIP7 = 10,     // Side strip LED 7. (For Mamba TE)
            RZLED_SIDE_STRIP8 = 11,     // Side strip LED 8. (For Mamba TE)
            RZLED_SIDE_STRIP9 = 12,     // Side strip LED 9. (For Mamba TE)
            RZLED_SIDE_STRIP10 = 13,    // Side strip LED 10. (For Mamba TE)
            RZLED_SIDE_STRIP11 = 14,    // Side strip LED 11. (For Mamba TE)
            RZLED_SIDE_STRIP12 = 15,    // Side strip LED 12. (For Mamba TE)
            RZLED_SIDE_STRIP13 = 16,    // Side strip LED 13. (For Mamba TE)
            RZLED_SIDE_STRIP14 = 17,    // Side strip LED 14. (For Mamba TE)
            RZLED_ALL = 0xFFFF
        } RZLED;
 
        typedef enum RZLED2
        {
            RZLED2_SCROLLWHEEL = 0x0203,  
            RZLED2_LOGO = 0x0703,  
            RZLED2_BACKLIGHT = 0x0403,  
            RZLED2_LEFT_SIDE1 = 0x0100,  
            RZLED2_LEFT_SIDE2 = 0x0200,  
            RZLED2_LEFT_SIDE3 = 0x0300,  
            RZLED2_LEFT_SIDE4 = 0x0400,  
            RZLED2_LEFT_SIDE5 = 0x0500,  
            RZLED2_LEFT_SIDE6 = 0x0600,  
            RZLED2_LEFT_SIDE7 = 0x0700,  
            RZLED2_BOTTOM1 = 0x0801,  
            RZLED2_BOTTOM2 = 0x0802,  
            RZLED2_BOTTOM3 = 0x0803,  
            RZLED2_BOTTOM4 = 0x0804,  
            RZLED2_BOTTOM5 = 0x0805,  
            RZLED2_RIGHT_SIDE1 = 0x0106,  
            RZLED2_RIGHT_SIDE2 = 0x0206,  
            RZLED2_RIGHT_SIDE3 = 0x0306,  
            RZLED2_RIGHT_SIDE4 = 0x0406,  
            RZLED2_RIGHT_SIDE5 = 0x0506,  
            RZLED2_RIGHT_SIDE6 = 0x0606,  
            RZLED2_RIGHT_SIDE7 = 0x0706   
        } RZLED2;
 
        typedef enum EFFECT_TYPE
        {
            CHROMA_NONE = 0,            
            CHROMA_BLINKING,            // Blinking effect (Deprecated and should not be used).
            CHROMA_BREATHING,           // Breathing effect (Deprecated and should not be used).
            CHROMA_CUSTOM,              // Custom effect type (Deprecated and should not be used).
            CHROMA_REACTIVE,            // Reactive effect (Deprecated and should not be used).
            CHROMA_SPECTRUMCYCLING,     // Spectrum cycling effect (Deprecated and should not be used).
            CHROMA_STATIC,              
            CHROMA_WAVE,                // Wave effect (Deprecated and should not be used).
            CHROMA_CUSTOM2,             
            CHROMA_STATIC2,             
            CHROMA_INVALID              
        } EFFECT_TYPE;
 
        // Static effect type (Deprecated and should not be used.
        typedef struct STATIC_EFFECT_TYPE
        {
            RZLED LEDId;        // LED Id.
            RZCOLOR Color;      // Colors.
        } STATIC_EFFECT_TYPE;
 
        typedef struct STATIC_EFFECT_TYPE2
        {
            RZCOLOR Color;      
        } STATIC_EFFECT_TYPE2;
 
        // Blinking effect (Deprecated and should not be used).
        typedef struct BLINKING_EFFECT_TYPE
        {
            RZLED LEDId;        // LED Id
            RZCOLOR Color;      // Color.
        } BLINKING_EFFECT_TYPE;
 
        // Breathing effect (Deprecated and should not be used).
        typedef struct BREATHING_EFFECT_TYPE
        {
            RZLED LEDId;        // LED Id
 
            // Breathing type.
            enum Type
            {
                ONE_COLOR = 1,  // 1 color (Only fill Color1).
                TWO_COLORS,     // 2 colors.
                RANDOM_COLORS,  // Random colors
                INVALID         // Invalid type
            } Type;
 
            RZCOLOR Color1;     // First color.
            RZCOLOR Color2;     // Second color.
        } BREATHING_EFFECT_TYPE;
 
        // Custom effect (Deprecated and should not be used).
        typedef struct CUSTOM_EFFECT_TYPE
        {
            RZCOLOR Color[MAX_LEDS];    // Array of colors.
        } CUSTOM_EFFECT_TYPE;
 
        typedef struct CUSTOM_EFFECT_TYPE2
        {
            RZCOLOR Color[MAX_ROW][MAX_COLUMN]; 
        } CUSTOM_EFFECT_TYPE2;
 
        // Reactive effect (Deprecated and should not be used).
        typedef struct REACTIVE_EFFECT_TYPE
        {
            RZLED LEDId;        // LED Id
 
            // Duration of the effect.
            enum Duration
            {
                DURATION_NONE = 0,  // No duration.
                DURATION_SHORT,     // Short duration.
                DURATION_MEDIUM,    // Medium duration.
                DURATION_LONG       // Long duration.
            } Duration;
 
            RZCOLOR Color;          // Color of the effect.
        } REACTIVE_EFFECT_TYPE;
 
        // No effect (Deprecated and should not be used).
        typedef struct NO_EFFECT_TYPE
        {
            RZLED LEDId;        // LED Id. \~chinese 颜色
        } NO_EFFECT_TYPE;
 
        // Spectrum cycling effect (Deprecated and should not be used).
        typedef struct SPECTRUMCYCLING_EFFECT_TYPE
        {
            RZLED LEDId;            // LED id.
        } SPECTRUMCYCLING_EFFECT_TYPE;
 
        // Wave effect (Deprecated and should not be used).
        typedef struct WAVE_EFFECT_TYPE
        {
            // Direction of the wave effect.
            enum Direction
            {
                FRONT_TO_BACK,      // Front to back
                BACK_TO_FRONT       // Back to front
            } Direction;
        } WAVE_EFFECT_TYPE;
    }
 
    namespace Headset
    {
        const RZSIZE MAX_LEDS = 5;
 
        typedef enum EFFECT_TYPE
        {
            CHROMA_NONE = 0,            
            CHROMA_STATIC,              
            CHROMA_BREATHING,           // Breathing effect (Deprecated and should not be used).
            CHROMA_SPECTRUMCYCLING,     // Spectrum cycling effect (Deprecated and should not be used).
            CHROMA_CUSTOM,              
            CHROMA_INVALID              
        } EFFECT_TYPE;
 
        typedef struct STATIC_EFFECT_TYPE
        {
            RZCOLOR Color;             
        } STATIC_EFFECT_TYPE;
 
        // Breathing effect (Deprecated and should not be used).
        typedef struct BREATHING_EFFECT_TYPE
        {
            RZCOLOR Color;             // Color.
        } BREATHING_EFFECT_TYPE;
 
        typedef struct CUSTOM_EFFECT_TYPE
        {
            RZCOLOR Color[MAX_LEDS];    
        } CUSTOM_EFFECT_TYPE;
    }
 
    namespace Mousepad
    {
        const RZSIZE MAX_LEDS = 15;
 
        typedef enum EFFECT_TYPE
        {
            CHROMA_NONE = 0,            
            CHROMA_BREATHING,           // Breathing effect (Deprecated and should not be used).
            CHROMA_CUSTOM,              
            CHROMA_SPECTRUMCYCLING,     // Spectrum cycling effect (Deprecated and should not be used).
            CHROMA_STATIC,              
            CHROMA_WAVE,                // Wave effect (Deprecated and should not be used).
            CHROMA_CUSTOM2,             
            CHROMA_INVALID,             
        } EFFECT_TYPE;
 
        // Chroma mousepad effects
        // Breathing effect (Deprecated and should not be used).
        typedef struct BREATHING_EFFECT_TYPE
        {
            // Breathing effects.
            enum Type
            {
                TWO_COLORS = 1,     // 2 colors
                RANDOM_COLORS,      // Random colors
                INVALID
            } Type;
            RZCOLOR Color1;    // First color.
            RZCOLOR Color2;    // Second color.
        } BREATHING_EFFECT_TYPE;
 
        typedef struct CUSTOM_EFFECT_TYPE
        {
            RZCOLOR Color[MAX_LEDS];    
        } CUSTOM_EFFECT_TYPE;
 
        typedef struct STATIC_EFFECT_TYPE
        {
            RZCOLOR Color;     
        } STATIC_EFFECT_TYPE;
 
        // Wave effect (Deprecated and should not be used).
        typedef struct WAVE_EFFECT_TYPE
        {
            // Direction of the wave effect.
            enum Direction
            {
                DIRECTION_NONE = 0,         // No direction.
                DIRECTION_LEFT_TO_RIGHT,    // Left to right.
                DIRECTION_RIGHT_TO_LEFT,    // Right to left.
                DIRECTION_INVALID           // Invalid direction.
            } Direction;                    // Direction of the wave.
        } WAVE_EFFECT_TYPE;
 
        namespace v2
        {
            const RZSIZE MAX_LEDS = 20;
 
            typedef struct CUSTOM_EFFECT_TYPE
            {
                RZCOLOR Color[MAX_LEDS];    
            } CUSTOM_EFFECT_TYPE;
        }
    }
 
    namespace Keypad
    {
        const RZSIZE MAX_ROW = 4;
 
        const RZSIZE MAX_COLUMN = 5;
 
        const RZSIZE MAX_KEYS = MAX_ROW * MAX_COLUMN;
 
        typedef enum EFFECT_TYPE
        {
            CHROMA_NONE = 0,            
            CHROMA_BREATHING,           // Breathing effect (Deprecated and should not be used).
            CHROMA_CUSTOM,              
            CHROMA_REACTIVE,            // Reactive effect (Deprecated and should not be used).
            CHROMA_SPECTRUMCYCLING,     // Spectrum cycling effect (Deprecated and should not be used).
            CHROMA_STATIC,              
            CHROMA_WAVE,                // Wave effect (Deprecated and should not be used).
            CHROMA_INVALID              
        } EFFECT_TYPE;
 
        // Chroma keypad effects
        // Breathing effect (Deprecated and should not be used).
        typedef struct BREATHING_EFFECT_TYPE
        {
            // Breathing effects.
            enum Type
            {
                TWO_COLORS = 1,     // 2 colors
                RANDOM_COLORS,      // Random colors
                INVALID             // Invalid type
            } Type;
            RZCOLOR Color1;    // First color.
            RZCOLOR Color2;    // Second color.
        } BREATHING_EFFECT_TYPE;
 
        typedef struct CUSTOM_EFFECT_TYPE
        {
            RZCOLOR Color[MAX_ROW][MAX_COLUMN]; 
        } CUSTOM_EFFECT_TYPE;
 
        // Reactive effect (Deprecated and should not be used).
        typedef struct REACTIVE_EFFECT_TYPE
        {
            // Duration of the effect.
            enum Duration
            {
                DURATION_NONE = 0,  // No duration.
                DURATION_SHORT,     // Short duration.
                DURATION_MEDIUM,    // Medium duration.
                DURATION_LONG,      // Long duration.
                DURATION_INVALID    // Invalid duration.
            } Duration;             // The time taken for the effect to fade away.
 
            RZCOLOR Color;          // Color of the effect
        } REACTIVE_EFFECT_TYPE;
 
        typedef struct STATIC_EFFECT_TYPE
        {
            RZCOLOR Color;  
        } STATIC_EFFECT_TYPE;
 
        // Wave effect (Deprecated and should not be used).
        typedef struct WAVE_EFFECT_TYPE
        {
            // Direction of the wave effect.
            enum Direction
            {
                DIRECTION_NONE = 0,         // No direction.
                DIRECTION_LEFT_TO_RIGHT,    // Left to right.
                DIRECTION_RIGHT_TO_LEFT,    // Right to left.
                DIRECTION_INVALID           // Invalid direction.
            } Direction;                    // Direction of the wave.
        } WAVE_EFFECT_TYPE;
    }
 
    namespace ChromaLink
    {
        const RZSIZE MAX_LEDS = 5;
 
        typedef enum EFFECT_TYPE
        {
            CHROMA_NONE = 0,            
            CHROMA_CUSTOM,              
            CHROMA_STATIC,              
            CHROMA_INVALID              
        } EFFECT_TYPE;
 
        typedef struct CUSTOM_EFFECT_TYPE
        {
            RZCOLOR Color[MAX_LEDS];    
        } CUSTOM_EFFECT_TYPE;
 
        typedef struct STATIC_EFFECT_TYPE
        {
            RZCOLOR Color;  
        } STATIC_EFFECT_TYPE;
    }
 
    namespace Desktop
    {
        const RZSIZE MAX_ROW = 19;  
 
        const RZSIZE MAX_COLUMN = 37;   
 
        const RZSIZE MAX_SIZE = MAX_ROW * MAX_COLUMN;
 
        typedef struct CUSTOM_EFFECT_TYPE
        {
            RZCOLOR Color[MAX_ROW][MAX_COLUMN]; 
        } CUSTOM_EFFECT_TYPE;
 
        typedef struct STATIC_EFFECT_TYPE
        {
            RZCOLOR Color;  
        } STATIC_EFFECT_TYPE;
    }
}
 
#endif