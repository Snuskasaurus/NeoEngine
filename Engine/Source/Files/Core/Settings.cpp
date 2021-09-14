#include "..\..\Includes\Core\Settings.h"

using namespace neo;

Settings* Settings::Instance()
{
    static Settings settings;
    return &settings;
}

void Settings::LoadFromFile()
{

}