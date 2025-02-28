# SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
# SPDX-License-Identifier: BSD-3-Clause

set(CMAKE_SKIP_INSTALL_RPATH ON CACHE BOOL "")
set(YARP_COMPILE_EXAMPLES ON CACHE BOOL "")
set(YARP_COMPILE_TESTS ON CACHE BOOL "")
set(YARP_DISABLE_FAILING_TESTS ON CACHE BOOL "")
set(YARP_ENABLE_EXAMPLES_AS_TESTS OFF CACHE BOOL "")
set(YARP_COMPILE_GUIS ON CACHE BOOL "")
set(YARP_COMPILE_yarpviz ON CACHE BOOL "")
set(YARP_COMPILE_libYARP_math ON CACHE BOOL "")
set(YARP_COMPILE_ALL_FAKE_DEVICES ON CACHE BOOL "")

# Avoid building Qt5 guis twice on macOS.
set(YARP_DISABLE_MACOS_BUNDLES ON CACHE BOOL "")

# Disable system SQLite3 (workaround for #2247)
set(YARP_USE_SYSTEM_SQLite3 OFF CACHE BOOL "")

set(ENABLE_yarpcar_human ON CACHE BOOL "")
set(ENABLE_yarppm_depthimage_to_mono ON CACHE BOOL "")
set(ENABLE_yarppm_depthimage_to_rgb ON CACHE BOOL "")
set(ENABLE_yarppm_segmentationimage_to_rgb ON CACHE BOOL "")
# set(ENABLE_yarpcar_mjpeg ON CACHE BOOL "")

set(ENABLE_yarpmod_SerialServoBoard ON CACHE BOOL "")
set(ENABLE_yarpmod_serialport ON CACHE BOOL "")
set(ENABLE_yarpmod_imuBosch_BNO055 ON CACHE BOOL "")
set(ENABLE_yarpmod_rpLidar ON CACHE BOOL "")
set(ENABLE_yarpmod_laserHokuyo ON CACHE BOOL "")
set(ENABLE_yarpmod_controlboard_nws_yarp ON CACHE BOOL "")
set(ENABLE_yarpmod_controlboardremapper ON CACHE BOOL "")
set(ENABLE_yarpcar_websocket ON CACHE BOOL "")

set(Qt5_DIR "/usr/local/opt/qt5/lib/cmake/Qt5")
