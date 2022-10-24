///////////////
 // SFML - Simple and Fast Multimedia Library
 // Copyright (C) 2007-2018 Laurent Gomila (laurent@sfml-dev.org)
 //
 // This software is provided 'as-is', without any express or implied warranty.
 // In no event will the authors be held liable for any damages arising from the use of this software.
 //
 // Permission is granted to anyone to use this software for any purpose,
 // including commercial applications, and to alter it and redistribute it freely,
 // subject to the following restrictions:
 //
 // 1. The origin of this software must not be misrepresented;
 //    you must not claim that you wrote the original software.
 //    If you use this software in a product, an acknowledgment
 //    in the product documentation would be appreciated but is not required.
 //
 // 2. Altered source versions must be plainly marked as such,
 //    and must not be misrepresented as being the original software.
 //
 // 3. This notice may not be removed or altered from any source distribution.
 //

 #ifndef SFML_OUTPUTSOUNDFILE_HPP
 #define SFML_OUTPUTSOUNDFILE_HPP

 // Headers
 #include <SFML/Audio/Export.hpp>
 #include <SFML/System/NonCopyable.hpp>
 #include <string>


 namespace sf
 {
     class SoundFileWriter;
    
         class SFML_AUDIO_API OutputSoundFile : NonCopyable
         {
         public:
            
                    OutputSoundFile();
            
                     ~OutputSoundFile();
            
                     bool openFromFile(const std::string & filename, unsigned int sampleRate, unsigned int channelCount);
            
            
         private:
            
                     void close();
            
                     // Member data
                     SoundFileWriter * m_writer;
             };
    
         } // namespace sf


 #endif // SFML_OUTPUTSOUNDFILE_HPP
