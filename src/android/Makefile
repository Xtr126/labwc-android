PKG_CONFIG?=pkg-config
WAYLAND_PROTOCOLS=$(shell $(PKG_CONFIG) --variable=pkgdatadir wayland-protocols)
WAYLAND_SCANNER=$(shell $(PKG_CONFIG) --variable=wayland_scanner wayland-scanner)

PKGS="wlroots-0.18" wayland-server xkbcommon

CFLAGS+=$(shell $(PKG_CONFIG) --cflags $(PKGS))
CFLAGS+=--target=x86_64-linux-android34

LIBS=$(shell $(PKG_CONFIG) --libs $(PKGS))
LIBS+=-lsync -lnativewindow -lcutils -landroid -lbinder_ndk -linputqueue -lc++_shared -laidl_shared
# wayland-scanner is a tool which generates C headers and rigging for Wayland
# protocols, which are specified in XML. wlroots requires you to rig these up
# to your build system yourself and provide them in the include path.
xdg-shell-protocol.h:
	$(WAYLAND_SCANNER) server-header \
		$(WAYLAND_PROTOCOLS)/stable/xdg-shell/xdg-shell.xml $@

tinywl.o: tinywl.c xdg-shell-protocol.h
	$(CC) -g -Werror $(CFLAGS) -fPIC -I. -DWLR_USE_UNSTABLE -o $@ -c $<

buffer_utils.o: buffer_utils.cpp
	$(CXX) -g -Werror $(CFLAGS) -fPIC -I. -DWLR_USE_UNSTABLE -o $@ -c $<

cros_gralloc_util.o: cros_gralloc_util.cpp
	$(CXX) -g -Werror $(CFLAGS) -fPIC -I. -DWLR_USE_UNSTABLE -o $@ -c $<

input_service.o: TinywlInputService.cpp
	$(CXX) -g $(CFLAGS) -fPIC -I. -I./aidl_source_output_dir/debug/out -I./libbinder_ndk_cpp -DWLR_USE_UNSTABLE -o $@ -c $<

main_service.o: TinywlMainService.cpp 
	$(CXX) -g $(CFLAGS) -fPIC -I. -I./aidl_source_output_dir/debug/out -I./libbinder_ndk_cpp -DWLR_USE_UNSTABLE -o $@ -c $<

buffer_presenter.o: buffer_presenter.cpp
	$(CXX) -g -Werror $(CFLAGS) -fPIC -I. -DWLR_USE_UNSTABLE -o $@ -c $<

ahb_wlr_allocator.o: ahb_wlr_allocator.c
	$(CC) -g -Werror $(CFLAGS) -fPIC -I. -DWLR_USE_UNSTABLE -o $@ -c $<

client_renderer.o: client_renderer.c
	$(CC) -g -Werror $(CFLAGS) -fPIC -I. -DWLR_USE_UNSTABLE -o $@ -c $<

ABI := $(shell getprop ro.product.cpu.abi | tr -d '\r')
APK_PATH := $(shell pm path com.xtr.tinywl 2>/dev/null | cut -d ':' -f 2 | tr -d '\r')
APK_DIR := $(shell dirname $(APK_PATH))
NATIVE_LIB_PATH=$(APK_DIR)/lib/$(ABI)

libtinywl.so: tinywl.o buffer_utils.o buffer_presenter.o cros_gralloc_util.o input_service.o ahb_wlr_allocator.o main_service.o client_renderer.o
	$(CC) $^ -g -Werror $(CFLAGS) $(LDFLAGS) $(LIBS) -L$(NATIVE_LIB_PATH) -fPIC -shared -o $@

clean:
	rm -f libtinywl.so tinywl.o buffer_utils.o buffer_presenter.o cros_gralloc_util.o input_service.o main_service.o ahb_wlr_allocator.o main_service.o client_renderer.o xdg-shell-protocol.h

.DEFAULT_GOAL=libtinywl.so
.PHONY: clean
