#ifndef _BIG_IMAGE_PROXY_H_
#define _BIG_IMAGE_PROXY_H_

#include "Image.h"
#include "BigImage.h"
#include <iostream>

class BigImageProxy : public Image
{
    public:
        BigImageProxy(string name, double size)
        {
            m_pBigImage = new BigImage(name, size);
        }

        virtual ~BigImageProxy()
        {
            if ( NULL != m_pBigImage )
            {
                delete m_pBigImage;
                m_pBigImage = NULL;
            }
        }

        void Show()
        {
            if (m_pBigImage != NULL )
            {
                if (m_pBigImage->getSize() < 500)
                {
                    m_pBigImage->Show();
                }
                else
                {
                    std::cout << "Picture is BIg" << std::endl;
                }
            }
        }
    private:
        BigImage *m_pBigImage;
};

#endif //_BIG_IMAGE_PROXY_H_
