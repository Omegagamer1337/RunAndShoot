#create executable
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE 
	"main.cpp" 
)

add_subdirectory(engine)
add_subdirectory(app)

#add libraries to executable
target_link_libraries(${PROJECT_NAME} PRIVATE external)