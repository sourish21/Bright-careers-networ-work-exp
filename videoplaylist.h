#pragma once
#include <string>
#include <vector>
#include <map>

/** A class used to represent a Playlist */

class VideoPlaylist {

    public:
        std::map<std::string, std::vector<std::string> >Available_playlist;
        std::string playList_Song;
        std::vector<std::string> playlistNames;
        VideoPlaylist() =default;
        void storeInMap(std::string play, std::string playlistName);

    
}Vm1;
