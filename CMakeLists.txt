CMAKE_MINIMUM_REQUIRED ( VERSION 2.8 )

PROJECT("Project1")

SET( Sources
    main.cpp
    student.cpp
    student.h
	argument.cpp
	argument.h
)

ADD_EXECUTABLE( ${PROJECT_NAME}
    WIN32
    ${Sources}
)
set_target_properties( ${PROJECT_NAME}
       PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE"
)