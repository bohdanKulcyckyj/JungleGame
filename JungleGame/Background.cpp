#include "Background.h"
#include "AssetsLoader.h"

Background::Background(string dir) {
	vector<string> imagesPaths = AssetsLoader().loadImagesFromDirectory(dir);
    //todo: vyresit aby se nemusel delat reverse
    reverse(imagesPaths.begin(), imagesPaths.end());
    this->loadLayersTextures(imagesPaths);
}

Background::Background(string dir, int w, int h) {
    this->layerWidth = w;
    this->layerHeight = h;

    vector<string> imagesPaths = AssetsLoader().loadImagesFromDirectory(dir);
    //todo: vyresit aby se nemusel delat reverse
    reverse(imagesPaths.begin(), imagesPaths.end());

    this->loadLayersTextures(imagesPaths);
}

void Background::loadLayersTextures(vector<string> paths) {
    vector<Texture2D> backgroundLayers;
    Image tmp;

    for (string path : paths) {
        //load image from path
        tmp = LoadImage(path.c_str()); //c_str for conversion sting to const char*

        //resize image
        ImageResize(&tmp, this->getLayerWidth(), this->getLayerHeight());

        //load texture from image & push to vector
        backgroundLayers.push_back(LoadTextureFromImage(tmp));
    }

    this->backgroundLayers = backgroundLayers;
}

vector<Texture2D> Background::getBackgroundLayers() {
    return this->backgroundLayers;
}

int Background::getLayerWidth() {
    return this->layerWidth;
}

int Background::getLayerHeight() {
    return this->layerHeight;
}