# http://www.utf8everywhere.org/
add_definitions(
    /D_UNICODE=1
    /DUNICODE=1
    /DLIBIME_EXPORTS

)

add_library(libIME2 SHARED
    # Core TSF part
    ImeModule.cpp
    ImeModule.h
    libIME.cpp
    libIME.h
    TextService.cpp
    TextService.h
    KeyEvent.cpp
    KeyEvent.h
    EditSession.cpp
    EditSession.h
    DisplayAttributeInfo.cpp
    DisplayAttributeInfo.h
    DisplayAttributeInfoEnum.cpp
    DisplayAttributeInfoEnum.h
    DisplayAttributeProvider.cpp
    DisplayAttributeProvider.h
    LangBarButton.cpp
    LangBarButton.h
    SinkAdvice.h
    Utils.cpp
    Utils.h
    ComPtr.h
    ComObject.h
    # GUI-related code
    DrawUtils.h
    DrawUtils.cpp
    Window.cpp
    Window.h
    ImeWindow.cpp
    ImeWindow.h
    MessageWindow.cpp
    MessageWindow.h
    CandidateWindow.h
    CandidateWindow.cpp
)

target_link_libraries(libIME2
    shlwapi.lib
)

set_target_properties(libIME2 PROPERTIES
	OUTPUT_NAME "libIME2"
	PREFIX ""
	DEBUG_POSTFIX "d"
)
