#add SDL3 which was created using git submodules add https://github.com/libsdl-org/SDL.git
add_subdirectory(SDL)
#add SDL3_ttf which was created using git submodules add https://github.com/libsdl-org/SDL_ttf.git
#add_subdirectory(SDL_ttf)
#add SDL3_ttf which was created using git submodules add https://github.com/libsdl-org/SDL_ttf.git
#add_subdirectory(SDL_image)

#create a vendor interface and link libraries to it
add_library(external INTERFACE)
target_link_libraries(external INTERFACE SDL3::SDL3)
#target_link_libraries(vendor INTERFACE SDL3_ttf::SDL3_ttf)
#target_link_libraries(vendor INTERFACE SDL3_image::SDL3_image)