revision=2d37d6e08791dd51c6541c344711b017eb9374bb

files_to_copy="teensy3/usb_dev.c teensy3/usb_mem.h teensy3/usb_mem.c
                teensy3/usb_dev.h teensy3/usb_desc.h teensy3/usb_desc.c
                teensy3/usb_names.h teensy3/usb_keyboard.h teensy3/usb_keyboard.c"

echo "Cloning repo..."
git clone https://github.com/PaulStoffregen/cores.git --depth 1
cd cores
git checkout ${revision}
echo "Copying files..."
for f in ${files_to_copy}; do
  cp ${files_to_copy} ../
done
