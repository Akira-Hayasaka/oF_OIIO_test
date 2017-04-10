#include "ofApp.h"

void ofApp::setup()
{
    ofImage testOverlay;
    testOverlay.load("overlay/test.jpg");
    
    string filename = "/Users/Akira/Project/20170213GrandCore/testDPX/170324_Cledis_for_TEST_7680x2160.dpx";
    
    
//    ImageInput *in = ImageInput::open(filename);
//    const ImageSpec &spec = in->spec();
//    int xres = spec.width;
//    int yres = spec.height;
//    int channels = spec.nchannels;
//    vector<unsigned char> pixels (xres*yres*channels);
//    in->read_image(TypeDesc::UINT8, &pixels[0]);
//    in->close();
//    ImageInput::destroy(in);
//
//    string outfile = ofToDataPath("read_unsigned_char_write_UINT8.dpx");
//    ImageOutput *out = ImageOutput::create(outfile);
//    ImageSpec outspec(xres, yres, channels, TypeDesc::UINT8);
//    out->open(outfile, spec);
//    out->write_image(TypeDesc::UINT8, &pixels[0]);
//    out->close();
//    ImageOutput::destroy(out);
//
//    ofPixels px;
//    px.setFromPixels(&pixels[0], xres, yres, channels);
//    img.setFromPixels(px);
//    
//    ofFbo fbo_GL_RGB;
//    fbo_GL_RGB.allocate(xres, yres, GL_RGB); // GL_RGB || GL_RGB32F_ARB
//    fbo_GL_RGB.begin();
//    ofClear(0);
//    img.draw(0, 0);
//    testOverlay.draw(2346, 1000);
//    fbo_GL_RGB.end();
//    
//    px.clear();
//    fbo_GL_RGB.readToPixels(px);
//    outfile = ofToDataPath("read_unsigned_char_update_GL_RGB_write_UINT8.dpx");
//    out = ImageOutput::create(outfile);
//    out->open(outfile, spec);
//    out->write_image(TypeDesc::UINT8, px.getData());
//    out->close();
//    ImageOutput::destroy(out);
    
    
    // ###
//    ImageInput *in = ImageInput::open(filename);
//    const ImageSpec &spec = in->spec();
//    int xres = spec.width;
//    int yres = spec.height;
//    int numpixels = xres * yres;
//    int channels = spec.nchannels;
//    vector<float> pixels(numpixels * channels);
//    in->read_image(TypeDesc::FLOAT, &pixels[0]);
//    in->close();
//    ImageInput::destroy(in);
//
//    string outfile = ofToDataPath("read_float_write_FLOAT.dpx");
//    ImageOutput *out = ImageOutput::create(outfile);
//    ImageSpec outspec(xres, yres, channels, TypeDesc::FLOAT);
//    out->open(outfile, spec);
//    out->write_image(TypeDesc::FLOAT, &pixels[0]);
//    out->close();
//    ImageOutput::destroy(out);
//
//    ofFloatPixels px;
//    px.setFromPixels(&pixels[0], xres, yres, channels);
//    img.setFromPixels(px);
//
//    ofFbo fbo_GL_RGB32F;
//    fbo_GL_RGB32F.allocate(xres, yres, GL_RGB32F); // GL_RGB || GL_RGB32F || GL_RGB32F_ARB
//    fbo_GL_RGB32F.begin();
//    ofClear(0);
//    img.draw(0, 0);
//    testOverlay.draw(2346, 1000);
//    fbo_GL_RGB32F.end();
//
//    px.clear();
//    fbo_GL_RGB32F.readToPixels(px);
//    outfile = ofToDataPath("read_float_update_GL_RGB32F_write_FLOAT.dpx");
//    out = ImageOutput::create(outfile);
//    out->open(outfile, spec);
//    out->write_image(TypeDesc::FLOAT, px.getData());
//    out->close();
//    ImageOutput::destroy(out);
    
    
    
    ImageInput *in = ImageInput::open(filename);
    const ImageSpec &spec = in->spec();
    int xres = spec.width;
    int yres = spec.height;
    int numpixels = xres * yres;
    int channels = spec.nchannels;
    vector<unsigned short> pixels(numpixels * channels);
    in->read_image(TypeDesc::UINT16, &pixels[0]);
    in->close();
    ImageInput::destroy(in);

    ofShortPixels px;
    px.setFromPixels(&pixels[0], xres, yres, channels);
    img.setFromPixels(px);
    
    ofFbo fbo_GL_RGB16F;
    fbo_GL_RGB16F.allocate(xres, yres, GL_RGB16F); // GL_RGB || GL_RGB32F || GL_RGB32F_ARB
    fbo_GL_RGB16F.begin();
    ofClear(0);
    img.draw(0, 0);
    testOverlay.draw(2346, 1000);
    fbo_GL_RGB16F.end();
    
    px.clear();
    fbo_GL_RGB16F.readToPixels(px);
    ImageSpec dpx10bitSpec(xres, yres, channels, TypeDesc::UINT16);
    dpx10bitSpec.set_format(TypeDesc::UINT16);
//    dpx10bitSpec.attribute("oiio:BitsPerPixel", 10);
    dpx10bitSpec.attribute("oiio:BitsPerSample", 10);
    dpx10bitSpec.attribute("oiio:ColorSpace", "Linear");
    dpx10bitSpec.attribute("dpx:Transfer", "Linear");
    dpx10bitSpec.attribute("dpx:Colorimetric", "Unspecified video");
    dpx10bitSpec.attribute("ImageDescription", "IMAGE DESCRIPTION DATA        ");
    dpx10bitSpec.attribute("dpx:LowQuantity", 0);
    dpx10bitSpec.attribute("dpx:HighData", 1023);
    dpx10bitSpec.attribute("dpx:HighQuantity", 2.047f);
    dpx10bitSpec.attribute("dpx:SequenceLength", 1);
    dpx10bitSpec.attribute("dpx:HeldCount", 1);
    dpx10bitSpec.attribute("dpx:FrameRate", 59.9401f);
    dpx10bitSpec.attribute("dpx:Version", "V1.0");
    dpx10bitSpec.attribute("dpx:InputDevice", "COMMIT");
    dpx10bitSpec.attribute("dpx:TemporalFrameRate", 59.9401f);
    dpx10bitSpec.attribute("dpx:LowData", 0);
    string outfile = ofToDataPath("read_UINT16_update_GL_RGB16F_write_UINT16_10bit.dpx");
    ImageOutput *out = ImageOutput::create(outfile);
    out->open(outfile, dpx10bitSpec);
    out->write_image(TypeDesc::UINT16, px.getData());
    out->close();
    ImageOutput::destroy(out);
    
    
    
    
//    ImageInput *in = ImageInput::open(filename);
//    const ImageSpec &inspec = in->spec();
//    int xres = inspec.width;
//    int yres = inspec.height;
//
//    struct Pixel { half r,g,b,a; float z; };
//    vector<Pixel> pixels(xres * yres);
//    in->read_image(TypeDesc::UNKNOWN, &pixels[0], sizeof(Pixel));
//    
//    string outfile = ofToDataPath("read_UNKNOWN_write_HALFPX.exr");
//    ImageOutput *out = ImageOutput::create(outfile);
//    
//    out->open(outfile, inspec);
//    out->write_image (TypeDesc::UNKNOWN, /* use channel formats */
//                      &pixels[0],            /* data buffer */
//                      sizeof(Pixel));    /* pixel stride */
//    
//    out->close();
//    ImageOutput::destroy(out);
    
    
//    ImageInput *in = ImageInput::open(filename);
//    const ImageSpec &inspec = in->spec();
//    int xres = inspec.width;
//    int yres = inspec.height;
//    int channels = inspec.nchannels;
//    struct Pixel { half r,g,b,a; float z; };
//    vector<Pixel> pixels(xres * yres);
//    in->read_image(TypeDesc::UNKNOWN, &pixels[0], sizeof(Pixel));
//    
//    string outfile = ofToDataPath("read_UNKNOWN_write_HALFPX_w_channelformats.exr");
//    ImageOutput *out = ImageOutput::create(outfile);
//    
//    ImageSpec spec(xres, yres, 5, TypeDesc::FLOAT);
//    spec.channelformats.push_back (TypeDesc::HALF);
//    spec.channelformats.push_back (TypeDesc::HALF);
//    spec.channelformats.push_back (TypeDesc::HALF);
//    spec.channelformats.push_back (TypeDesc::HALF);
//    spec.channelformats.push_back (TypeDesc::FLOAT);
//    spec.channelnames.clear ();
//    spec.channelnames.push_back ("R");
//    spec.channelnames.push_back ("G");
//    spec.channelnames.push_back ("B");
//    spec.channelnames.push_back ("A");
//    spec.channelnames.push_back ("Z");
//    
//    out->open(outfile, spec);
//    out->write_image (TypeDesc::UNKNOWN, /* use channel formats */
//                      &pixels[0],        /* data buffer */
//                      sizeof(Pixel));    /* pixel stride */
//    
//    out->close();
//    ImageOutput::destroy(out);
//    
//    vector<float> f;
//    for (auto p : pixels)
//    {
//        f.push_back(p.r.operator float());
//        f.push_back(p.g.operator float());
//        f.push_back(p.b.operator float());
//        f.push_back(p.a.operator float());
//    }
//    ofFloatPixels fpxs;
//    fpxs.setFromPixels(&f[0], xres, yres, 4);
//    img.setFromPixels(fpxs);
}

void ofApp::update(){}

void ofApp::draw()
{
    img.draw(0, 0, img.getWidth() * 0.2, img.getHeight() * 0.2);
}

void ofApp::keyPressed(int key){}
void ofApp::keyReleased(int key){}
void ofApp::mouseMoved(int x, int y ){}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::mouseReleased(int x, int y, int button){}
void ofApp::mouseEntered(int x, int y){}
void ofApp::mouseExited(int x, int y){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){}
