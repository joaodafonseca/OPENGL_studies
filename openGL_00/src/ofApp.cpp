#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    selectedScene = 0;
    
    scene.push_back(new brickTexture());
    scene.push_back(new simpleTexture());
    scene.push_back(new multipleTexture());
    scene.push_back(new CubeMapping());
    scene.push_back(new EnvironmentMapping());
    scene.push_back(new GlyphBombing());
    scene.push_back(new ProceduralStripes());
    scene.push_back(new ToyBall());
    scene.push_back(new Lattice());
    scene.push_back(new HemisphereLighting());
    scene.push_back(new ImageBasedLighting());
    scene.push_back(new SphericalHarmonicsLighting());
    
    selectedScene = scene.size()-1;

}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
   
    scene[selectedScene]->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    scene[selectedScene]->draw();
}

//--------------------------------------------------------------
void ofApp::changeScene(int _i){
    selectedScene+=_i;
    if(selectedScene<0)selectedScene=scene.size()-1;
    else if(selectedScene>scene.size()-1)selectedScene=0;
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key=='r')scene[selectedScene]->reloadShader();
    else if(key==OF_KEY_LEFT)changeScene(-1);
    else if (key==OF_KEY_RIGHT)changeScene(+1);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
