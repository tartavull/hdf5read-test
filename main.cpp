#include <QCoreApplication>
#include <H5Cpp.h>
#include <QDebug>
#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /* Open an existing file. */
    H5::H5File file( "channel.hdf5", H5F_ACC_RDONLY );

    /* Open an existing dataset. */
    H5::DataSet dataset = file.openDataSet( "/main" );

    // Get the class of the datatype that is used by the dataset.
    H5T_class_t type_class = dataset.getTypeClass();

    //Get class of datatype and print message if it's an integer.
    if( type_class == H5T_FLOAT ){
        qDebug() << "Data set has FLOAT type";

        H5::FloatType floatType = dataset.getFloatType();

        // Get order of datatype and print message if it's a little endian.
        H5std_string order_string;
        H5T_order_t order = floatType.getOrder( order_string );
        qDebug() << QString::fromStdString(order_string);

        //Get size of the data element stored in file and print it.
        size_t size = floatType.getSize();
        cout << "Data size is " << size << endl;


        //Get dataspace of the dataset.
        H5::DataSpace dataspace = dataset.getSpace();

        // Get the number of dimensions in the dataspace.
        int rank = dataspace.getSimpleExtentNdims();
        // Get the dimension size of each dimension in the dataspace and display them.

        hsize_t dims_out[3];
        const hsize_t ndims = dataspace.getSimpleExtentDims( dims_out, NULL);
        cout << "rank " << rank << ", dimensions " << endl;
        for (int i=0 ; i < ndims; ++i){
            cout << (unsigned long)(dims_out[i]) << " x " << endl;

        }

        int size_array = dims_out[0] * dims_out[1] * dims_out[2];
        float* data_out = new float[size_array];
        dataset.read( data_out, H5::PredType::NATIVE_FLOAT);

        for(int row = 0; row < 10 ; ++row ){

            printf("%a",data_out[row]);

            std::cout << data_out[row] << std::endl;
        }

        }
    return a.exec();
}
