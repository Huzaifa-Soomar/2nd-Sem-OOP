
// ......... Under supervision of Sir taloot..........//

#include <iostream>
using namespace std;

class CloudStorage
{
public:
    virtual void uploadFile(string fileName) = 0;
    virtual void downloadFile(string fileName) = 0;
    virtual void deleteFile(string fileName) = 0;
    virtual void listFiles() = 0;
};

class AWSStorage : public CloudStorage
{
public:
    void uploadFile(string fileName) override
    {

        cout << "Uploading " << fileName << " to AWS S3... Done \n ";
    }
    void downloadFile(string fileName) override
    {
        cout << "Downloading " << fileName << " from AWS Storage ... Done \n";
    }

    void deleteFile(string fileName) override
    {
        cout << "Deleting " << fileName << " from AWS Storage ... Done \n ";
    }

    void listFiles() override
    {
        cout << "List Files : \n";
    }
};

class GoogleDriveStorage : public CloudStorage
{
public:
    void uploadFile(string fileName) override
    {

        cout << "Uploading " << fileName << " to Google Drive... Done \n ";
    }
    void downloadFile(string fileName) override
    {
        cout << "Downloading " << fileName << " from Google Drive \n";
    }

    void deleteFile(string fileName) override
    {
        cout << "Deleting " << fileName << " from Google Drive ... Done \n ";
    }

    void listFiles() override
    {
        cout << "List Files : \n";
    }
};

class DropboxStorage : public CloudStorage
{
public:
    void uploadFile(string fileName) override
    {

        cout << "Uploading " << fileName << " to Dropbox Storage... Done \n ";
    }
    void downloadFile(string fileName) override
    {
        cout << "Downloading " << fileName << " from Dropbox Storage \n";
    }

    void deleteFile(string fileName) override
    {
        cout << "Deleting " << fileName << " from Dropbox Storage ... Done \n ";
    }

    void listFiles() override
    {
        cout << "List Files : \n";
    }
};

class OneDriveStorage : public CloudStorage
{
public:
    void uploadFile(string fileName) override
    {

        cout << "Uploading " << fileName << " to One Drive Storage... Done \n ";
    }
    void downloadFile(string fileName) override
    {
        cout << "Downloading " << fileName << " from one Drive Storage \n";
    }

    void deleteFile(string fileName) override
    {
        cout << "Deleting " << fileName << " from  one Drive Storage ... Done \n ";
    }

    void listFiles() override
    {
        cout << "List Files : \n";
    }
};

int main()
{
    CloudStorage *aws = new AWSStorage();
    cout << "...........AWS Storage........... \n";

    aws->uploadFile("report.pdf");
    aws->deleteFile("report.pdf");
    aws->downloadFile("report.pdf");

    CloudStorage *gd = new GoogleDriveStorage();
    cout << "...............Google Drive Storage......... \n";

    gd->uploadFile("report.pdf");
    gd->deleteFile("report.pdf");
    gd->downloadFile("report.pdf");

    CloudStorage *ds = new DropboxStorage();
    cout << "................Dropbox Storage Storage........... \n";

    ds->uploadFile("report.pdf");
    ds->deleteFile("report.pdf");
    ds->downloadFile("report.pdf");

    CloudStorage *od = new OneDriveStorage();
    cout << "...............One Drive Storage Storage............. \n";

    od->uploadFile("report.pdf");
    od->deleteFile("report.pdf");
    od->downloadFile("report.pdf");

    return 0;
}