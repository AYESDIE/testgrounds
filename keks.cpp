//
// Created by ayesdie on 07-09-2022.
//

#include <iostream>
#include <vector>
#include <cmath>

class img {
    int h, w;
    std::vector<int> buffer;

public:
    img() {}
    img(int h, int w, const std::vector<int> &buffer) : h(h), w(w), buffer(buffer) {}

    int getw() const {return w;}
    int geth() const {return h;}
    std::vector<int> getbuffer() {return buffer;}

    friend std::ostream &operator<<(std::ostream &os, const img &img) {
        for (int i = 0; i < img.h; ++i) {
            for (int j = 0; j < img.w; ++j) {
                os << img.buffer[(i * img.w) + j] << " ";
            }
            os << "\n";
        }
        return os;
    }
};

img rotate90(img im) {
    std::vector<int> buffer = im.getbuffer();
    std::vector<int> kekw(im.geth() * im.getw());
    for (int j = 0; j < im.geth(); ++j) {
        for (int i = 0; i < im.getw(); ++i) {
            kekw[im.geth() - 1 - j + im.geth() * i] = buffer[i + im.getw()*j];
        }
    }
    std::cout << "\n";
    return img(im.getw(), im.geth(), kekw);
}

img rotate270(img im) {
    std::vector<int> buffer = im.getbuffer();
    std::vector<int> kekw(im.geth() * im.getw());
    for (int j = 0; j < im.geth(); ++j) {
        for (int i = 0; i < im.getw(); ++i) {
            kekw[im.geth() * (im.getw() - 1) - i * im.geth() + j] = buffer[i + im.getw()*j];
        }
    }
    std::cout << "\n";
    return img(im.getw(), im.geth(), kekw);
}

img nrotate90(img im) {
    std::vector<int> buffer = im.getbuffer();
    std::vector<int> kekw(im.geth() * im.getw());
    for (int j = 0; j < im.geth(); ++j) {
        for (int i = 0; i < im.getw(); ++i) {
            //std::cout << im.geth() - 1 - j + im.geth() * i << " " << i + im.geth()*j << " | " ;
            int offset = std::floor(std::abs(im.geth() - im.getw())/2);

            if (im.getw() < im.geth()) {
                int x_dest = (im.geth() - 1 - j + im.geth() * i);
                x_dest = x_dest + 2;
                x_dest = x_dest + (im.geth() - j);
                //x_dest = x_dest -
                if ((x_dest >= im.getw() * offset) && (x_dest < im.getw() * (im.getw() + offset)))
                {
                    kekw[x_dest] = buffer[i + im.getw()*j];
                    std::cout << x_dest << " ";
                }
            }
            else {
                int x_new = im.geth() - j - 1;
                int y_new = i;


                if ((y_new >= offset) && (y_new < im.geth() + offset)) {
                    std::cout << x_new << " " << y_new << " |";
                    kekw[y_new + im.getw() * x_new] =  buffer[i + im.getw()*j];
                }
            }
        }
    }
    std::cout << "\n";
    return img(im.geth(), im.getw(), kekw);
}

int main() {
    img im = img(3, 6, std::vector<int>(
            {0, 1, 2, 3, 4, 5,
             6, 7, 8, 9, 10, 11,
             12, 13, 14, 15, 16, 17}));
    std::cout << im << std::endl << rotate90(im) << std::endl << nrotate90(im);
    //std::cout << im << std::endl << rotate270(im) << std::endl << nrotate270(im);
    return 0;
}
