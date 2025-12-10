#!/bin/sh

CHROOT_PATH=""
TARGET_USER=""

usage() {
    echo "Usage: $0 --chroot-path <path> --user <username>"
    echo ""
    echo "  --chroot-path  The path to the chroot directory."
    echo "  --user         The target username inside the chroot."
    exit 1
}

while [ "$#" -gt 0 ]; do
    case "$1" in
        --chroot-path)
            if [ -n "$2" ] && [ "$2" != "--user" ]; then
                CHROOT_PATH="$2"
                shift 
            else
                echo "Error: --chroot-path requires a value."
                usage
            fi
            ;;
        --user)
            if [ -n "$2" ] && [ "$2" != "--chroot-path" ]; then
                TARGET_USER="$2"
                shift 
            else
                echo "Error: --user requires a value."
                usage
            fi
            ;;
        -h|--help)
            usage
            ;;
        *)
            echo "Unknown parameter passed: $1"
            usage
            ;;
    esac
    shift 
done

if [ -z "$CHROOT_PATH" ] || [ -z "$TARGET_USER" ]; then
    echo "Error: Both --chroot-path and --user are required."
    usage
fi

export XDG_RUNTIME_DIR_IN_CHROOT="/tmp/x-termux"
export XDG_RUNTIME_DIR="$CHROOT_PATH/$XDG_RUNTIME_DIR_IN_CHROOT"
export TMPDIR="$CHROOT_PATH/tmp"

su -c mkdir -p "$XDG_RUNTIME_DIR"
su -c chmod 777 "$XDG_RUNTIME_DIR"

sh ./start.sh -s "sh ./chroot_shell.sh --chroot-path \"$CHROOT_PATH\" --user $TARGET_USER"