if( NOT TARGET poScene )
	get_filename_component( poScene_SOURCE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../src/poScene" ABSOLUTE )
	get_filename_component( CINDER_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../.." ABSOLUTE )

	FILE(GLOB poScene_SOURCES ${poScene_SOURCE_PATH}/*.cpp)

	add_library( poScene ${poScene_SOURCE_PATH}/poScene )

	target_include_directories( poScene PUBLIC "${poScene_SOURCE_PATH}" )
	target_include_directories( poScene SYSTEM BEFORE PUBLIC "${CINDER_PATH}/include" )

	if( NOT TARGET cinder )
		    include( "${CINDER_PATH}/proj/cmake/configure.cmake" )
		    find_package( cinder REQUIRED PATHS
		        "${CINDER_PATH}/${CINDER_LIB_DIRECTORY}"
		        "$ENV{CINDER_PATH}/${CINDER_LIB_DIRECTORY}" )
	endif()
	target_link_libraries( poScene PRIVATE cinder )
endif()
