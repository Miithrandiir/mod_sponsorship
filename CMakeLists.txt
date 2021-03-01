AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/SponsorshipHelper.cpp")
AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/SponsorshipPlayer.cpp")
AC_ADD_SCRIPT_LOADER("SponsorShip" "${CMAKE_CURRENT_LIST_DIR}/src/SponsorshipLoader.h")


AC_ADD_CONFIG_FILE("${CMAKE_CURRENT_LIST_DIR}/conf/sponsorship.conf.dist")