#include "videoplayer.h"
#include "videoplaylist.h"

#include <iostream>
#include<string.h>
#include<cstdlib>
#include<ctime>

void VideoPlayer::numberOfVideos() {
  std::cout << mVideoLibrary.getVideos().size() << " videos in the library"
            << std::endl;
}

void VideoPlayer::showAllVideos() {
    std::cout << "Here's a list of all videos:";
  for(auto i : mVideoLibrary.getVideos()){

    std::cout << i.getTitle() << " " << "(" << i.getVideoId() << ")";
    std::cout << "[";
    for( auto j : i.getTags()){
      std::cout << j << " ";
    }
    std::cout <<"]\n";
  }
}

void VideoPlayer::playVideo(const std::string& videoId) {
  

  if(playStatus == true){
      std::cout << "Stopped playing: " << Mv.getCurrentVideo()<<"\n";
      playStatus = false;
    }
 
  for(auto i : mVideoLibrary.getVideos()){
    if(videoId.compare(i.getVideoId()) == 0){
      std::cout << "Playing: " << i.getTitle();
      Mv.setCurrentVideo(i.getTitle());
      playStatus = true;
      exists =true;
      break;
    }
    else{
      playStatus = false;
    }
  }
  if(exists == false){
    std::cout << "Cannot play video. Video doesn't exists";
  }

}

void VideoPlayer::stopVideo() {

  if(playStatus == false){
    std::cout << "Cannot stop video: No video is currently playing\n";
  }
  else{
    std::cout << "Stopping video: " << this->getCurrentVideo();
  }
}

void VideoPlayer::playRandomVideo() {
  srand(time(0));
  int casem = std::rand() % 5;
  switch(casem){
    case 0:
      playVideo("funny_dogs_video_id");
      break;
    case 1:
      playVideo("amazing_cats_video_id");
      break;
    case 2:
      playVideo("another_cat_video_id");
      break;
    case 3:
      playVideo("life_at_google_video_id");
      break;
    case 4:
      playVideo("nothing_video_id");
      break;
  }
  
}

void VideoPlayer::pauseVideo() {
  if(Mv.getCurrentVideo() == "\0"){
    std::cout << "Cannot pause video: No video is currently playing\n";
  }
  else{
    if(pause == true){
      std::cout << "Video already paused: "<< Mv.getCurrentVideo();
    }
    else{
      std::cout << "Pausing video: " << Mv.getCurrentVideo();
    }
  }
}

void VideoPlayer::continueVideo() {
  if(pause == true){
    std::cout << "Continuing video: " << this->getCurrentVideo();
  }
  else{
    std::cout << "Cannot continue video: Video is not paused.";
  }
}

void VideoPlayer::showPlaying() {
    if (playStatus == true) {
        std::cout << "Currently playing: " << this->CurrentSong;
    }

    else {
        std::cout << "No video is currently playing.";
    }
}

void VideoPlayer::createPlaylist(const std::string& playlistName) {
 
  bool f = true;
  for(auto i: Vm1.playlistNames){
    if(playlistName == i){
      std::cout << "Cannot create playlist: A playlist with the same name already exists.";
      f = false;
      break;
    }
  }
  if(f == true){
    Vm1.playlistNames.push_back(playlistName);
    std::cout << "Succesfully created new playlist: " << playlistName;
  }
}

void VideoPlayer::addVideoToPlaylist(const std::string& playlistName,
                                     const std::string& videoId) {
    bool added = false; 
    bool vid_exists = false;
    bool playlisT_exist = false;

    for (auto j : mVideoLibrary.getVideos()) {
        if (videoId == j.getVideoId()) {
            Vm1.playList_Song == j.getTitle();
            vid_exists = true;
        }
    }
    if (vid_exists == false)
        std::cout << "Cannot add to " << playlistName << ". Video doesn't exist.";
    for (auto i : Vm1.playlistNames) {

        if (playlistName == i) {
            playlisT_exist = true;
        }  
    }

    for (auto i : Vm1.Available_playlist ) {
        for (auto j : i.second ) {
            if (Vm1.playList_Song == j)
                vid_exists = true;
        }
    }


   if(added == false && vid_exists == true && playlisT_exist == true)
        Vm1.storeInMap(Vm1.playList_Song, playlistName);
}

void VideoPlayer::showAllPlaylists() {
    if (sizeof(Vm1.playlistNames) == 0) {
        std::cout << "No playlists exists yet";

    }
    else {
        std::cout << "Showing all playlists: ";
        for (auto i : Vm1.playlistNames) {
            std::cout << i << "\n";

        }
    }
}

void VideoPlayer::showPlaylist(const std::string& playlistName) {

    }

    for (auto i : Vm1.Available_playlist) {
        if (Vm1.Available_playlist.find(playlistName) != Vm1.Available_playlist.end()) {
            std::cout << "Showing playlist: " << playlistName;
            for (auto j : i.second) {
                std::cout << j;
            }
                
        }
    }
  
}

void VideoPlayer::removeFromPlaylist(const std::string& playlistName,
                                     const std::string& videoId) {
    for (auto k : mVideoLibrary.getVideos()) {
        if (videoId == k.getVideoId()) {
            Vm1.playList_Song == k.getTitle();
            vid_exists = true;
        }


    for (auto i : Vm1.Available_playlist) {
        if (Vm1.Available_playlist.find(playlistName) != Vm1.Available_playlist.end()) {
            std::cout << "Showing playlist: " << playlistName;
            for (auto j : i.second) {
                if (j == Vm1.playList_Song) {
                    Vm1.Available_playlist.erase(j);
                }
            }

        }
    }
  
}

void VideoPlayer::clearPlaylist(const std::string& playlistName) {
  std::cout << "clearPlaylist needs implementation" << std::endl;
}

void VideoPlayer::deletePlaylist(const std::string& playlistName) {
  std::cout << "deletePlaylist needs implementation" << std::endl;
}

void VideoPlayer::searchVideos(const std::string& searchTerm) {
  std::cout << "searchVideos needs implementation" << std::endl;
}

void VideoPlayer::searchVideosWithTag(const std::string& videoTag) {
  std::cout << "searchVideosWithTag needs implementation" << std::endl;
}

void VideoPlayer::flagVideo(const std::string& videoId) {
  std::cout << "flagVideo needs implementation" << std::endl;
}

void VideoPlayer::flagVideo(const std::string& videoId, const std::string& reason) {
  std::cout << "flagVideo needs implementation" << std::endl;
}

void VideoPlayer::allowVideo(const std::string& videoId) {
  std::cout << "allowVideo needs implementation" << std::endl;
}

void VideoPlayer::setCurrentVideo(std::string& SongName){
  CurrentSong = SongName;
}


std::string VideoPlayer::getCurrentVideo(){
  return CurrentSong;
}