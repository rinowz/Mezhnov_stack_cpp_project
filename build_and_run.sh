rm -rf build
mkdir build
cd build
cmake ..
make
./a_mezh_1
cat ./ResTest.txt
rm -rf build
echo "Its OKAY"