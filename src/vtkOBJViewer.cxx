/****************************************************************************
*   vtkOBJViewer.cxx
*
*   Created by:     Michael Kuczynski
*   Created on:     28/03/2019
*   Version:        1.0
*   Description:    
****************************************************************************/

#include "helperFunctions.hxx"

int main(int argc, char* argv[])
{
    /***************************************************************
    *   Check input arguements
    ***************************************************************/
    if ( argc != 2 )
    {
        std::cout << "ERROR: Incorrect program usage." << std:: endl;
        std::cout << "Correct usage: " << argv[0] << " <OBJ_File_Directory>" << std::endl;
        return EXIT_FAILURE;
    }

    vtkSmartPointer<vtkOBJReader> objReader;
    vtkSmartPointer<vtkPolyData> obj = vtkSmartPointer<vtkPolyData>::New();

    /***************************************************************
    *   Read in the provided OBJ file
    ***************************************************************/
    // Create a variable for the input arguement (if valid type).
    std::string objFile = "";

    // Verify that the provided input arguements are valid
    // if ( !checkInputs( argv[1] )
    // {
    //     return EXIT_FAILURE;
    // }
    // else
    // {
    //     objFile = argv[2];
    // }
    objFile = argv[1];

    // Read in the OBJ file
    objReader = vtkSmartPointer<vtkOBJReader>::New();
    objReader->SetFileName( objFile.c_str() );
    objReader->Update();

    obj = objReader->GetOutput();

    /***************************************************************
    *   Add mappers, actors, renderer, and setup the scene
    ***************************************************************/
    std::cout << "\n**Rendering the scene** \n";

    vtkSmartPointer<vtkPolyDataMapper> targetMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    targetMapper->SetInputData( obj );

    vtkSmartPointer<vtkActor> targetActor = vtkSmartPointer<vtkActor>::New();
    targetActor->SetMapper( targetMapper );
    targetActor->GetProperty()->SetColor( 1, 1, 1 );
    targetActor->GetProperty()->SetOpacity( 1.0 );
    targetActor->GetProperty()->SetPointSize( 4 );
    targetActor->GetMapper()->ScalarVisibilityOff();

    // Create the renderer and render window
    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();

    vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->AddRenderer( renderer );
    vtkSmartPointer<vtkRenderWindowInteractor> interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    interactor->SetRenderWindow( renderWindow );

    renderer->AddActor( targetActor );
    renderer->SetBackground( 0.0, 0.0, 0.0 );

    renderWindow->Render();

    std::cout << "Done! \n";

    interactor->Start();

    return EXIT_SUCCESS;
}