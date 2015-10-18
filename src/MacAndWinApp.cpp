
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class MacAndWinApp : public AppNative {
private:
  Vec3f rot;
  
public:
  void prepareSettings(Settings* settings);
  void setup();
  void mouseDown(MouseEvent event);
  void update();
  void draw();
};

void MacAndWinApp::prepareSettings(Settings* settings) {
  settings->disableFrameRate();
}

void MacAndWinApp::setup() {
  rot = Vec3f::zero();
  
  gl::enableDepthRead();
  gl::enableDepthWrite();
}

void MacAndWinApp::mouseDown(MouseEvent event) {}

void MacAndWinApp::update() {
  rot += 0.4f;
}

void MacAndWinApp::draw() {
	gl::clear(Color(0.4f, 0.4f, 0.4f));
  
  gl::pushModelView();
  gl::translate(getWindowCenter());
  gl::rotate(rot);
  gl::drawCoordinateFrame(40, 20, 5);
  gl::popModelView();
}

CINDER_APP_NATIVE( MacAndWinApp, RendererGl )
