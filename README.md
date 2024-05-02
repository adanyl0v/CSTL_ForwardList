[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]

<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#key-features">Key Features</a></li>
        <li><a href="#target-audience">Target Audience</a></li>
        <li><a href="#benefits">Benefits</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
  </ol>
</details>

## <a name="about-the-project">About the project</a>

CSTL Forward List is a C implementation of the popular C++ Standard Template Library (STL) container `std::forward_list`.
It provides a singly linked list data structure that offers efficient insertion and removal operations.

This library is designed for programmers who:

- Want to leverage the functionality of C++'s `std::forward_list` in their C projects.
- Appreciate the memory efficiency of singly linked lists compared to doubly linked lists.
- Prioritize efficient insertion, removal, and move operations in their C code.

### <a name="key-features">Key Features</a>

- **Efficient memory usage:** By only storing references to the next element in the list, `CSTL_Forward_List` offers a memory-saving alternative to doubly linked lists.
- **Constant time operations:** Insertion and removal operations are typically performed in constant time, making it ideal for scenarios where frequent modifications are required.
- **Lightweight implementation:** Designed to be a lightweight library, minimizing its footprint in your C projects.

### <a name="target-audience">Target Audience</a>

This library is aimed at C programmers who:

- Are familiar with C data structures and concepts.
- Have a basic understanding of linked lists.
- Seek to enhance their C code with efficient dynamic data structures.

### <a name="benefits">Benefits</a>

- **Improved performance:** Enjoy the speed benefits of constant time operations for common list manipulations.
- **Memory optimization:** Reduce memory consumption compared to doubly linked lists when you don't need to traverse backwards.
- **Flexibility:** Integrate a well-established data structure pattern into your C projects.

## <a name="getting-started">Getting started</a>

### <a name="prerequisites">Prerequisites</a>

To build and install the library, you must have `CMake` at least version 3.5 installed.
* Ubuntu
  ``` sh
  sudo apt-get install cmake
  ```
* MacOS
  ``` sh
  sudo port install cmake
  ```
* Windows
  [https://cmake.org/download/](cmake.org/download)

### <a name="installation">Installation</a>

1. Clone the repo
   ``` sh
   git clone git@github.com:adanyl0v/CSTL_ForwardList.git
   ```
2. Install the library:
    * Go to the directory where the cloned repository is located
    * Run the configuration script `scripts/configure.sh`
    * Run the build script `scripts/build.sh`
    * Run the installation script `scripts/install.sh` (administrator privileges may be required)
> [!NOTE]
> Before running any script, it's recommended to read it for a better understanding of the configuration, build and installation processes 
3. Link the library to your project
   ``` cmake
   find_package(CSTL_ForwardList REQUIRED)
   link_libraries(CSTL_ForwardList::CSTL_ForwardList)
   ```
   
> [!IMPORTANT]
> For correct work with the library, you will have to install some additional libraries. 
> The installation process remains the same. Here are links to their GitHub repositories:
> * [CSTL_Exception](https://github.com/adanyl0v/CSTL_Exception.git)
> * [CSTL_SmartPointer](https://github.com/adanyl0v/CSTL_SmartPointer.git)
> * [CSTL_Iterator](https://github.com/adanyl0v/CSTL_Iterator.git)

## <a name="contributing">Contributing</a>

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b v[chosen project version]-feat-AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin v[chosen project version]-feat-AmazingFeature`)
5. Open a Pull Request

## <a name="license">License</a>

Distributed under the MIT License. See `LICENSE` for more information.

[contributors-shield]: https://img.shields.io/github/contributors/adanyl0v/CSTL_ForwardList.svg?style=for-the-badge
[contributors-url]: https://github.com/adanyl0v/CSTL_ForwardList/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/adanyl0v/CSTL_ForwardList.svg?style=for-the-badge
[forks-url]: https://github.com/adanyl0v/CSTL_ForwardList/forks
[stars-shield]: https://img.shields.io/github/stars/adanyl0v/CSTL_ForwardList.svg?style=for-the-badge
[stars-url]: https://github.com/adanyl0v/CSTL_ForwardList/stargazers
[issues-shield]: https://img.shields.io/github/issues/adanyl0v/CSTL_ForwardList.svg?style=for-the-badge
[issues-url]: https://github.com/adanyl0v/CSTL_ForwardList/issues
[license-shield]: https://img.shields.io/github/license/adanyl0v/CSTL_ForwardList.svg?style=for-the-badge
[license-url]: https://github.com/adanyl0v/CSTL_ForwardList/LICENSE