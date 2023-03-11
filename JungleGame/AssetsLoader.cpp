#include "AssetsLoader.h"
#include <filesystem>

namespace fs = std::filesystem;

vector<string> AssetsLoader::loadImagesFromDirectory(string dir) {
    cout << "neco se deje" << endl;
    vector<std::string> imagePaths; // vector to store image paths

    // path to directory containing images
    fs::path directoryPath = dir;

    for (const auto& entry : fs::directory_iterator((fs::path)dir))
    {
        // check if the entry is a file and ends with a valid image extension
        if (entry.is_regular_file() &&
            (entry.path().extension() == ".png" ||
                entry.path().extension() == ".jpg" ||
                entry.path().extension() == ".jpeg"))
        {
            // add the file path to the vector
            imagePaths.push_back(entry.path().string());
        }
    }

    return imagePaths;
}