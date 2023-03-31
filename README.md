## The Dumb Become Singers

video link https://youtu.be/vdSBNa-Adfw

This project is to help deaf people cognize the language system and make them feel the joy of music by tracking and recognizing the movement of different shapes of the mouth in real-time through the face tracker and Maximliam tools in openframeworks, which produce the resonance of different vowels.

In the critical thinking class, there is a section on accessible design. one of the principles of Crip Technoscience is to consider practical design principles for people with disabilities when designing. I need to use inclusive design to build empathy for different scenarios of functional deficits so that I can better think about need pain points, and interaction behaviors, and tap into more essential human motivations. This class made me think about accessibility design for people with disabilities in a new way and made me pay attention to the deaf group. I found out that deaf people are divided into two major groups, one is those who can hear and cannot speak; the other is those who cannot hear and cannot speak. I contacted organizations for people with disabilities and interviewed several deaf people, who said, "Although we are deaf, we can generally hear with the help of hearing aids." "So how do you speak? One is the language that simulates hearing, thinking in words, which translates into sign language expression, and the other is through the eyes, visual image thinking understanding." "We also sometimes understand language by looking at each other's lips, face, and tongue movements." "The way we feel the sound is all through the tactile sense of feeling the vibration of sound. "

How can we break through the sign language expression of deaf people and make them think with sound? I was inspired by the lip reading method, where the shape of the mouth changes to make the language understood. We learn language by starting with the vowels A, E, I, O, and U. The shape of the mouth is used to understand the pronunciation. Therefore I connect the vowel sounds with the shape of the mouth according to their vocalization. When you move your mouth in a specific way, you hear the vowel sound in that shape. I studied piano for 7 years when I was a child, and vocal tones are variations of the tones of the language. Scales in music are also determined by pitch, and the learning of vocal tone helps to feel a sense of music. Connecting vowels to pitch helps deaf people feel the music changes. Also inspired by Auto-Tune, the distorted vocal effect makes the sound made by people the feeling of electronic music, because I also talk about the sound to make the effect of vibrato and delay, so that deaf people can feel the mystery of music.

To design this project, I needed to use three tools: face tracker, Maximliam, and GUI.

With the face tracker trying to update the image every frame, the camera has a new frame to process with the program to run. Check if the camera has a new frame so that it can use the new frame. Tracking the mouth and eyebrows, mapping to any note in the current scale based on the height of the mouth, elongating the vowels by the width of the mouth, and adding vibrato based on the height of the eyebrows.

Edit the frequencies and effects of the tones with Maximliam.

I build the 5 vowels with the appropriate vowel frequencies and decibels. https://www.classes.cs.uchicago.edu/archive/1999/spring/CS295/Computing_Resources/Csound/CsManual3.48b1.HTML/Appendices/table3.html
The vowels are pronounced in C major by default. The names of the tones of the music are CDEFGAB by major key, calling out their frequencies. https://musicinspace.bandcamp.com/track/c-13081-hz  I then calculated each scale based on the indices of the major and minor keys. Corresponding to the keyboard, a = C, w = C#, s = D, e = D#, d = E, f = F, t = F#, g = G, y = G#, h = A, u = A#, j = B
ofSoundStream This class controls and reads the computed sound data, calling audioIn() when the system receives any sound, and calling audioOut() before the system sends the sound to the sound card, telling the RtAudio library to start and process the audio from the microphone. https://openframeworks.cc/ documentation/sound/ofSoundStream/ 

With Gui, added panel controls to adjust volume, delayVolume, delaySize, delayFeedback, and transposition.

Since it was the first time I came across face tracker, I didn't expect the biggest difficulty in installing it, which almost made me give up on the plugin. After adding it, there was a problem with not finding opencv/cv.h. I got the answer from the forum that ofxFaceTracker is based on an older version of opencv. oF 0.11.0 uses opencv4, so I downloaded a lower version of oF. After replacing the lower version of oF, I had a new problem testing the face tracker. file not found: /user/lib/ libstdc++.6.dylib for architecture x86_64 clang: error: linker command failed with exit code 1 (use -v to see invocation). So the forum helped me, once again.
https://forum.openframeworks.cc/t/building-in-macos-11-0-big-sur/36581 
I replaced the latest version of fmodex dylib in libs/fmodex/lib/osx/. Run script at build stage to change to install_name_tool -change @rpath/libfmod.dylib @executable_path/... /Frameworks/libfmodex.dylib"$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/$PRODUCT_NAME"; and according to the online tutorial, add -deep_name_tool to the build setting/signing/other code signing flags, and then finally I can run it. But during the run, the error came up again, Thread 1 :hit program assert, so I suspended the thread in the left column. Then I was prompted, [ error ] Make sure you've placed the files face2.tracker, face.tri and face.con in the data/model/ folder. I learned from the readme of the face tracker plugin that I need I need to make a copy of the libs/FaceTracker/model/ directory in example-*/bin/data/model/ of each example. You can do this by hand, or python setup.py will take care of this for you. Once you have solved the plugin problem, everything will be fine.









