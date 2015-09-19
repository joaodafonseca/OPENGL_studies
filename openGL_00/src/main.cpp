#include "ofMain.h"
#include "ofApp.h"

int main()
{
    ofGLWindowSettings settings;
    settings.width = 1280;
    settings.height = 720;
    settings.setGLVersion(3,3);
    ofCreateWindow(settings);
    
    ofRunApp( new ofApp());
}