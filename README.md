# JackRussell

<img style="float: right;" align="left" src="https://images.unsplash.com/photo-1675870405034-3a2fb38852be" width="200">

A C++ Publish/Subscriber Library 

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE) [![GitHub release](https://img.shields.io/github/release/ZigRazor/JackRussell.svg)](https://GitHub.com/ZigRazor/JackRussell/releases/) [![CMake](https://github.com/ZigRazor/JackRussell/actions/workflows/cmake.yml/badge.svg)](https://github.com/ZigRazor/JackRussell/actions/workflows/cmake.yml) 

[![codecov](https://codecov.io/gh/ZigRazor/JackRussell/graph/badge.svg?token=24SM5HBW6C)](https://codecov.io/gh/ZigRazor/JackRussell) [![CodeFactor](https://www.codefactor.io/repository/github/zigrazor/JackRussell/badge)](https://www.codefactor.io/repository/github/zigrazor/jackRussell)

[![Generic badge](https://img.shields.io/badge/required-C++20-Green.svg)](https://shields.io/) [![Generic badge](https://img.shields.io/badge/Required-CMake3.16-Green.svg)](https://shields.io/)

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)
- [Acknowledgements](#acknowledgements)

## Description

JackRussell is a C++ Publish/Subscriber Library. This project aims to fulfill a framework with easy-to-use mechanisms of Publish and Subscriber. By using JackRussell, users can:
- Create a Topics;
- Publish to Topic;
- Create Subscribers Classes;
- Register the Subscribers Classes to one or more Topics;
- Manage the message received by Subscribers

## Features

- Topic Manager Singleton
- Topic Class
- Subscriber Interface

## Installation

To install and set up JackRussell, follow these steps:

1. **Clone the repository:**
   ```bash
   git clone https://github.com/ZigRazor/JackRussell.git
   ```
2. **Navigate to the project directory:**
  ```bash
  cd JackRussell
  ```
3. **Prepare CMake:**
  ```bash
  mkdir build
  cd build
  cmake ..
 ```
4. **Install Library**
   ```bash
   make install
   ```
     
## Usage

You can use the Library in your project with CMake adding the following lines:

```cmake
CPMAddPackage(
    NAME JackRussell
    GITHUB_REPOSITORY ZigRazor/JackRussell
    GIT_TAG origin/main
)
```
or install it and the add to the include path *{StandardIncludePath}/DogBreeds/JackRussell* and to the linking_path *{StandardLinkingPath}/DogBreeds/JackRussell*. 

For simple use you can see the [Example](https://github.com/ZigRazor/JackRussell/tree/main/example)
For more detailed usage instructions, refer to the documentation.

## Contributing
We welcome contributions to JackRussell! To contribute, follow these steps:

1. **Fork the repository.**
2. **Create a new branch:**
  ```bash
  git checkout -b feature/your-feature-name
  ```
3. **Make your changes and commit them:**
  ```bash
  git commit -m "Add your commit message"
  ```
4. **Push to the branch:**
  ```bash
  git push origin feature/your-feature-name
  ```
5. **Create a pull request.**

Please read our [contributing guidelines](https://github.com/ZigRazor/JackRussell/blob/main/CONTRIBUTING.md) for more details.

## License
This project is licensed under the MIT License. See the [LICENSE](https://github.com/ZigRazor/JackRussell/blob/main/LICENSE) file for details.

## Contact
If you have any questions, suggestions, or feedback, feel free to reach out:

- Email: zigrazor@gmail.com
- GitHub Issues: [issues](https://github.com/ZigRazor/JackRussell/issues)

## Acknowledgements
We would like to thank the following individuals for their support:

[![Contributors](https://contrib.rocks/image?repo=zigrazor/JackRussell)](https://github.com/ZigRazor/JackRussell/graphs/contributors) 

## Credits

Photo by <a href="https://unsplash.com/@nataliekinnear?utm_content=creditCopyText&utm_medium=referral&utm_source=unsplash">Natalie Kinnear</a> on <a href="https://unsplash.com/photos/a-black-and-white-dog-sitting-on-top-of-a-lush-green-field-QscvNWv6HUo?utm_content=creditCopyText&utm_medium=referral&utm_source=unsplash">Unsplash</a>
  
  
