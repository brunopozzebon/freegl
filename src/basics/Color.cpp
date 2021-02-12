//
// Created by bruno on 03/02/2021.
//

#include "Color.h"
#include "../utils/Convertion.h"

Color::Color() {
    this->r = 1.0f;
    this->g = 1.0f;
    this->b = 1.0f;
    this->a = 1.0f;
}

Color::Color(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = 1.0f;
}

Color::Color(float r, float g, float b, float a) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

Color::Color(int r, int g, int b, float a) {
    this->r = (float) r / 255;
    this->g = (float) g / 255;
    this->b = (float) b / 255;
    this->a = a;
}

Color::Color(int r, int g, int b) {
    this->r = (float) r / 255;
    this->g = (float) g / 255;
    this->b = (float) b / 255;
    this->a = 1.0f;
}

Color::Color(string hex){
    if(hex[0]!='#' || (hex.size() != 4  && hex.size() != 7 && hex.size() != 9) ){
        Color(255, 255, 255);
    }
    if(hex.size() ==4 ){
        char rCode = hex[1];
        char gCode = hex[2];
        char bCode = hex[3];

        int convertedR = Convertion::charHexToInt(rCode);
        int convertedG = Convertion::charHexToInt(gCode);
        int convertedB = Convertion::charHexToInt(bCode);

        this->r = (float)((convertedR*16)+convertedR)/255;
        this->g = (float)((convertedG*16)+convertedG)/255;
        this->b = (float)((convertedB*16)+convertedB)/255;
        this->a = 1.0f;
    }else{
        char rCode1 = hex[1];
        char rCode2 = hex[2];

        char gCode1 = hex[3];
        char gCode2 = hex[4];

        char bCode1 = hex[5];
        char bCode2 = hex[6];

        int convertedR1 = Convertion::charHexToInt(rCode1);
        int convertedR2 = Convertion::charHexToInt(rCode2);

        int convertedG1 = Convertion::charHexToInt(gCode1);
        int convertedG2 = Convertion::charHexToInt(gCode2);

        int convertedB1 = Convertion::charHexToInt(bCode1);
        int convertedB2 = Convertion::charHexToInt(bCode2);

        this->r = (float)((convertedR1*16)+convertedR2)/255;
        this->g = (float)((convertedG1*16)+convertedG2)/255;
        this->b = (float)((convertedB1*16)+convertedB2)/255;

        if(hex.size() == 7){
            this->a = 1.0f;
        }else{
            char aCode1 = hex[7];
            char aCode2 = hex[8];

            int convertedA1 = Convertion::charHexToInt(aCode1);
            int convertedA2 = Convertion::charHexToInt(aCode2);

            this->a = (float)((convertedA1*16)+convertedA2)/255;
        }
    }
}

Color Color::AliceBlue = Color("#F0F8FF");
Color Color::AntiqueWhite = Color("#FAEBD7");
Color Color::Aqua = Color("#00FFFF");
Color Color::Aquamarine = Color("#7FFFD4");
Color Color::Azure = Color("#F0FFFF");
Color Color::Beige = Color("#F5F5DC");
Color Color::Bisque = Color("#FFE4C4");
Color Color::Black = Color("#000000");
Color Color::BlanchedAlmond = Color("#FFEBCD");
Color Color::Blue = Color("#0000FF");
Color Color::BlueViolet = Color("#8A2BE2");
Color Color::Brown = Color("#A52A2A");
Color Color::BurlyWood = Color("#DEB887");
Color Color::CadetBlue = Color("#5F9EA0");
Color Color::Chartreuse = Color("#7FFF00");
Color Color::Chocolate = Color("#D2691E");
Color Color::Coral = Color("#FF7F50");
Color Color::CornflowerBlue = Color("#6495ED");
Color Color::Cornsilk = Color("#FFF8DC");
Color Color::Crimson = Color("#DC143C");
Color Color::Cyan = Color("#00FFFF");
Color Color::DarkBlue = Color("#00008B");
Color Color::DarkCyan = Color("#008B8B");
Color Color::DarkGoldenRod = Color("#B8860B");
Color Color::DarkGray = Color("#A9A9A9");
Color Color::DarkGrey = Color("#A9A9A9");
Color Color::DarkGreen = Color("#006400");
Color Color::DarkKhaki = Color("#BDB76B");
Color Color::DarkMagenta = Color("#8B008B");
Color Color::DarkOliveGreen = Color("#556B2F");
Color Color::Darkorange = Color("#FF8C00");
Color Color::DarkOrchid = Color("#9932CC");
Color Color::DarkRed = Color("#8B0000");
Color Color::DarkSalmon = Color("#E9967A");
Color Color::DarkSeaGreen = Color("#8FBC8F");
Color Color::DarkSlateBlue = Color("#483D8B");
Color Color::DarkSlateGray = Color("#2F4F4F");
Color Color::DarkSlateGrey = Color("#2F4F4F");
Color Color::DarkTurquoise = Color("#00CED1");
Color Color::DarkViolet = Color("#9400D3");
Color Color::DeepPink = Color("#FF1493");
Color Color::DeepSkyBlue = Color("#00BFFF");
Color Color::DimGray = Color("#696969");
Color Color::DimGrey = Color("#696969");
Color Color::DodgerBlue = Color("#1E90FF");
Color Color::FireBrick = Color("#B22222");
Color Color::FloralWhite = Color("#FFFAF0");
Color Color::ForestGreen = Color("#228B22");
Color Color::Fuchsia = Color("#FF00FF");
Color Color::Gainsboro = Color("#DCDCDC");
Color Color::GhostWhite = Color("#F8F8FF");
Color Color::Gold = Color("#FFD700");
Color Color::GoldenRod = Color("#DAA520");
Color Color::Gray = Color("#808080");
Color Color::Grey = Color("#808080");
Color Color::Green = Color("#008000");
Color Color::GreenYellow = Color("#ADFF2F");
Color Color::HoneyDew = Color("#F0FFF0");
Color Color::HotPink = Color("#FF69B4");
Color Color::IndianRed = Color("#CD5C5C");
Color Color::Indigo = Color("#4B0082");
Color Color::Ivory = Color("#FFFFF0");
Color Color::Khaki = Color("#F0E68C");
Color Color::Lavender = Color("#E6E6FA");
Color Color::LavenderBlush = Color("#FFF0F5");
Color Color::LawnGreen = Color("#7CFC00");
Color Color::LemonChiffon = Color("#FFFACD");
Color Color::LightBlue = Color("#ADD8E6");
Color Color::LightCoral = Color("#F08080");
Color Color::LightCyan = Color("#E0FFFF");
Color Color::LightGoldenRodYellow = Color("#FAFAD2");
Color Color::LightGray = Color("#D3D3D3");
Color Color::LightGrey = Color("#D3D3D3");
Color Color::LightGreen = Color("#90EE90");
Color Color::LightPink = Color("#FFB6C1");
Color Color::LightSalmon = Color("#FFA07A");
Color Color::LightSeaGreen = Color("#20B2AA");
Color Color::LightSkyBlue = Color("#87CEFA");
Color Color::LightSlateGray = Color("#778899");
Color Color::LightSlateGrey = Color("#778899");
Color Color::LightSteelBlue = Color("#B0C4DE");
Color Color::LightYellow = Color("#FFFFE0");
Color Color::Lime = Color("#00FF00");
Color Color::LimeGreen = Color("#32CD32");
Color Color::Linen = Color("#FAF0E6");
Color Color::Magenta = Color("#FF00FF");
Color Color::Maroon = Color("#800000");
Color Color::MediumAquaMarine = Color("#66CDAA");
Color Color::MediumBlue = Color("#0000CD");
Color Color::MediumOrchid = Color("#BA55D3");
Color Color::MediumPurple = Color("#9370D8");
Color Color::MediumSeaGreen = Color("#3CB371");
Color Color::MediumSlateBlue = Color("#7B68EE");
Color Color::MediumSpringGreen = Color("#00FA9A");
Color Color::MediumTurquoise = Color("#48D1CC");
Color Color::MediumVioletRed = Color("#C71585");
Color Color::MidnightBlue = Color("#191970");
Color Color::MintCream = Color("#F5FFFA");
Color Color::MistyRose = Color("#FFE4E1");
Color Color::Moccasin = Color("#FFE4B5");
Color Color::NavajoWhite = Color("#FFDEAD");
Color Color::Navy = Color("#000080");
Color Color::OldLace = Color("#FDF5E6");
Color Color::Olive = Color("#808000");
Color Color::OliveDrab = Color("#6B8E23");
Color Color::Orange = Color("#FFA500");
Color Color::OrangeRed = Color("#FF4500");
Color Color::Orchid = Color("#DA70D6");
Color Color::PaleGoldenRod = Color("#EEE8AA");
Color Color::PaleGreen = Color("#98FB98");
Color Color::PaleTurquoise = Color("#AFEEEE");
Color Color::PaleVioletRed = Color("#D87093");
Color Color::PapayaWhip = Color("#FFEFD5");
Color Color::PeachPuff = Color("#FFDAB9");
Color Color::Peru = Color("#CD853F");
Color Color::Pink = Color("#FFC0CB");
Color Color::Plum = Color("#DDA0DD");
Color Color::PowderBlue = Color("#B0E0E6");
Color Color::Purple = Color("#800080");
Color Color::Red = Color("#FF0000");
Color Color::RosyBrown = Color("#BC8F8F");
Color Color::RoyalBlue = Color("#4169E1");
Color Color::SaddleBrown = Color("#8B4513");
Color Color::Salmon = Color("#FA8072");
Color Color::SandyBrown = Color("#F4A460");
Color Color::SeaGreen = Color("#2E8B57");
Color Color::SeaShell = Color("#FFF5EE");
Color Color::Sienna = Color("#A0522D");
Color Color::Silver = Color("#C0C0C0");
Color Color::SkyBlue = Color("#87CEEB");
Color Color::SlateBlue = Color("#6A5ACD");
Color Color::SlateGray = Color("#708090");
Color Color::SlateGrey = Color("#708090");
Color Color::Snow = Color("#FFFAFA");
Color Color::SpringGreen = Color("#00FF7F");
Color Color::SteelBlue = Color("#4682B4");
Color Color::Tan = Color("#D2B48C");
Color Color::Teal = Color("#008080");
Color Color::Thistle = Color("#D8BFD8");
Color Color::Tomato = Color("#FF6347");
Color Color::Turquoise = Color("#40E0D0");
Color Color::Violet = Color("#EE82EE");
Color Color::Wheat = Color("#F5DEB3");
Color Color::White = Color("#FFFFFF");
Color Color::WhiteSmoke = Color("#F5F5F5");
Color Color::Yellow = Color("#FFFF00");
Color Color::YellowGreen = Color("#9ACD32");

glm::vec3 Color::toVec3() {
    return glm::vec3(this->r, this->g, this->b);
}
