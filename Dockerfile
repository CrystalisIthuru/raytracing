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
