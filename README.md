# Honey [![License](https://img.shields.io/github/license/CleverSource/Honey.svg)](https://github.com/CleverSource/Honey/blob/master/LICENSE)

Honey is primarily an early-stage interactive application and rendering engine for Windows. Currently not much is implemented.

## Getting Started
Visual Studio 2017 or 2019 is recommended, Honey is officially untested on other development environments whilst we focus on a Windows build.

Start by cloning the repository with `git clone --recursive https://github.com/CleverSource/Honey`.

If the repository was cloned non-recursively previously, use `git submodule update --init` to clone the necessary submodules.

## The Plan
The plan for Honey is two-fold: to create a powerful 3D engine, but also to serve as an education tool for people that wish to learn the design and architecture of a game engine.

### Main features to come:
- Fast 2D rendering (UI, particles, sprites, etc.)
- High-fidelity Physically-Based 3D rendering (this will be expanded later, 2D to come first)
- Support for Mac, Linux, Android and iOS
	- Native rendering API support (DirectX, Vulkan, Metal)
- Fully featured viewer and editor applications
- Fully scripted interaction and behavior
- Integrated 3rd party 2D and 3D physics engine
- Procedural terrain and world generation
- Artificial Intelligence
- Audio system




## Short term goals :
*Note: this is subject to change at any time!*

By the end 2020, we want to make a game using the Honey game engine. Not like the time I made a game in one hour using the engine, but this time by using the proper tools that would be required to make a game with Honey. This means we need to add a full 2D workflow:

- Design the game scene by using Honeynut, the Honey editor,
- Test the game inside Honeynut, including the ability to save/load the created game,
- Load and play the game inside Sandbox.

We want everyone to be able to play the game on all desktop platforms (Windows, Mac and Linux). When this is implemented, another attempt at the "Creating a game in one hour using Honey" will be made to see how far the engine has become.

[![Twitter](https://img.shields.io/badge/%40RyanAlsoClever--blue.svg?style=social&logo=Twitter)](https://twitter.com/RyanAlsoClever)
