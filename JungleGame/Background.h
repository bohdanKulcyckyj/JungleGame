#pragma once
#include <string>
#include <vector>
#include "raylib.h"

using namespace std;

class Background
{
private:
	vector<Texture2D> backgroundLayers;
	int layerWidth = GetScreenWidth();
	int layerHeight = GetScreenHeight();
public:
	Background(string dir);
	Background(string dir, int w, int h);

	vector<Texture2D> getBackgroundLayers();
	int getLayerWidth();
	int getLayerHeight();

	void loadLayersTextures(vector<string> paths);

	void DrawBackground();
};

