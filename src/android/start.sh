export XKB_CONFIG_ROOT=/data/data/com.termux/files/usr/share/xkeyboard-config-2
ABI=$(getprop ro.product.cpu.abi | tr -d '\r')
APK_PATH=$(pm path com.xtr.tinywl 2>/dev/null | cut -d ':' -f 2 | tr -d '\r')
APK_DIR=$(dirname "$APK_PATH")
NATIVE_LIB_PATH="$APK_DIR/lib/$ABI"

/system/bin/app_process -Djava.library.path=./:/system/lib64/:"$NATIVE_LIB_PATH" \
                        -Djava.class.path="$APK_PATH" / com.xtr.tinywl.Tinywl "$@"
