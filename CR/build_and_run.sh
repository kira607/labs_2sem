echo "Build started"
echo ""
echo ""

cd cmake-build-debug/ || exit
cmake ..
make

echo ""
echo "Running..."
echo "==============================================="
echo ""

./CourseWork