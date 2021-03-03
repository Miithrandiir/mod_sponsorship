
CU_SET_PATH("CMAKE_Sponsorship_DIR" "${CMAKE_CURRENT_LIST_DIR}")

AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/SponsorshipHelper.hpp")
AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/SponsorshipHelper.cpp")
AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/SponsorshipGroup.hpp")
AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/SponsorshipGroup.cpp")
AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/SponsorshipPlayer.cpp")
AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/SponsorshipPlayer.hpp")
AC_ADD_SCRIPT_LOADER("SponsorShip" "${CMAKE_CURRENT_LIST_DIR}/src/SponsorshipLoader.h")


AC_ADD_CONFIG_FILE("${CMAKE_CURRENT_LIST_DIR}/conf/sponsorship.conf.dist")