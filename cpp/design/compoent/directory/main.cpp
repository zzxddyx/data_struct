#include "Dir.h"
#include "File.h"
#include "IFile.h"

#include <iostream>

void showTree(IFile *root, int level)
{
    if( NULL == root )
    {
        return;
    }

    for (int i = 0; i < level; ++i)
    {
        std::cout << "\t";
    }
    root->display();

    list<IFile *> *file = root->getChild();
    if ( NULL != file )
    {
        for (list<IFile*>::iterator iter = file->begin(); iter != file->end(); ++iter)
        {
            // child
            if ( NULL == (*iter)->getChild())
            {
                for (int i = 0; i <= level; ++i)
                {
                    std::cout << "\t";
                }
                (*iter)->display();
            }
            else
            {
                showTree(*iter, level+1);
            }
        }
    }
}

int main(void)
{
    Dir *root = new Dir("C:");
    Dir *dir1 = new Dir("Intel");
    Dir *dir2 = new Dir("Windows");

    File *dir1_file1 = new File("intel-1");
    File *dir1_file2 = new File("intel-2") ;

    File *dir2_file1 = new File("Web");
    File *dir2_file2 = new File("System");
    File *dir2_file3 = new File("Help");

    root->add(dir1);
    root->add(dir2);

    dir1->add(dir1_file1);
    dir1->add(dir1_file2);

    dir2->add(dir2_file1);
    dir2->add(dir2_file2);
    dir2->add(dir2_file3);

    showTree(root, 0);

    return 0 ;
}

