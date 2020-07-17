FROM amytabb/docker_ubuntu16_essentials

LABEL maintainer="Adrian Darian"
LABEL maintainer.email="adarian@ucmerced.edu"
LABEL version="0.1.0"

# Copy all files to Docker Container
COPY . /app

# Assign working directory
WORKDIR /app/

# Clean out Lab's previous tests
RUN make clean

# Compile Lab
RUN make all

# Run against the Grade to check for accuracy and success
ENTRYPOINT ["bash", "Grade"]