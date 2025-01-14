# Caesar Cipher Tool<sup><sup>TM</sup></sup> - C++ Edition
A simple program use to Encipher/Decipher text to/from Caesar Cipher. And yes, there are more versions of this program from other programming languages.

## How this thing works
1. It slices the alphabet from the index of shift then add the sliced part to the start of the alphabet.
2. Find the index of every character in user input in the alphabet and append the character with the same index into the output. Add the character into the output if it doesn't exist in the alphabet.

## Functionality(ies)
1. Encipher/Decipher text to/from Caesar Cipher.

## Installation
If you're on Windows, grab the [release](https://github.com/uwungu01-rep/caesar-cipher-tool-cpp.edition/releases/tag/tag) .exe so you can save yourself the pain of getting GCC working.

## Building from source
Now, assuming you're not using Windows or you're using Windows and you're just hate yourself for some reason.
<ol tpye="1">
    <li>
        On Windows:
        <ol type=I">
            <li>
                Follow the instruction from <a href="https://code.visualstudio.com/docs/cpp/config-mingw">here</a> to get GCC (God bless your soul).
            </li>
            <li>
                Open the source folder (the folder contains main.cpp), right click and choose "Open in Terminal".
            </li>
            <li>
                In terminal, run:
                
```
g++ main.cpp
```
Optionally, you can add "-o" at the end + whatever name you want the .exe to be. The command should look like this:
```
g++ main.cpp -o {name}
```
With name as the name you want the .exe to be.
            </li>
        </ol>
    </li>
    <li>
        On linux: Follow the instruction from [here](https://code.visualstudio.com/docs/cpp/config-linux) to get GCC. Navigate to the source folder (the folder contains main.cpp) and open your terminal there. Everything else should be the same as Windows.
    </li>
</ol>
No MacOS because I don't like to.

## License
This project is licensed under the GNU General Public License 3.0, check [LICENSE](LICENSE) for more details.
