docker build -t sh_check -f check.dockerfile .
docker run -it $(pwd)/..:/host sh_check <plugin> <pluglet>
