FROM rockylinux:8.9

# Install System Packages
RUN dnf update --assumeyes && \
    dnf install -y epel-release && \
    dnf install -y \
        cmake \
        gcc-toolset-11 \
        git \
        vim && \
    dnf clean all && \
    rm -rfv /var/cache/dnf

SHELL ["scl", "enable", "gcc-toolset-11"]

# Install Eigen
RUN git -c http.sslVerify=false clone https://gitlab.com/libeigen/eigen.git --branch 3.4.0 --depth 1 && \
    cmake -S eigen -B eigen/build -DCMAKE_INSTALL_PREFIX=/opt/eigen && \
    cmake --build eigen/build -j $(nproc) -t install && \
    rm -rfv eigen

ENV CMAKE_PREFIX_PATH=/opt/eigen: