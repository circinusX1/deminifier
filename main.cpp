/*
BSD 2-Clause License

Copyright (c) 2021, circinusX1
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

int main(int argc, char *argv[])
{
    if (argc==1)return 0;
    FILE* pf = ::fopen(argv[1],"rb");
    char buff[8912];
    std::string tabs={0};
    if(pf)
    {
        while(!feof(pf)){
            size_t b = fread(buff,1,sizeof(buff)-1,pf);
            if(b)
            {
                buff[b]=0;
                size_t j=0;
                for(size_t j=0;j<b;j++)
                {
                    char c= buff[j];
                    if(c=='{'){
                        std::cout << "\n";
                        std::cout << tabs;
                        std::cout << c;
                        std::cout << "\n";
                        tabs.append("    ");
                        std::cout << tabs;
                    }
                    else if(c=='}'){
                        if(tabs.length()>4)
                            tabs=tabs.substr(0,tabs.length()-4);
                        else
                            tabs="";

                        std::cout << "\n";
                        std::cout << tabs;
                        std::cout << c;

                    }
                    else if(c==';'){
                        std::cout << c;
                        std::cout << "\n";
                        std::cout << tabs;
                    }
                    else {
                        std::cout << c;
                    }
                }
            }
            if(feof(pf)){
                break;
            }
        }
        ::fclose(pf);
    }
    return 0;
}
