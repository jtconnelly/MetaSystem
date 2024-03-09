add_library(MetaSystemLib SHARED AnyType.h AnyType.cpp MetaInfo.cpp MetaInfo.h MetaInfoWriter.h MetaInfoWriter.cpp)
include(GenerateExportHeader)
generate_export_header(MetaSystemLib)
target_include_directories(MetaSystemLib PUBLIC
	${CMAKE_CURRENT_LIST_DIR}
	${CMAKE_CURRENT_BINARY_DIR})