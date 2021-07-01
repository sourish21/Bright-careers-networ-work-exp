#include "videoplaylist.h"
#include <iostream>
#include<string.h>


//Store in map will be kind of 2d 
void VideoPlaylist::storeInMap(std::string play, std::string playlistName)
{
	Available_playlist[playlistName].push_back(play);
}



