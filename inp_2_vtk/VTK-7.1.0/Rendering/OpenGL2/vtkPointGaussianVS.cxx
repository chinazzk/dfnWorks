/* DO NOT EDIT.
 * Generated by ../../bin/vtkEncodeString-7.1
 * 
 * Define the vtkPointGaussianVS string.
 *
 * Generated from file: /home/nknapp/dfnworks-main/inp_2_vtk/VTK-7.1.0/Rendering/OpenGL2/glsl/vtkPointGaussianVS.glsl
 */
#include "vtkPointGaussianVS.h"
const char *vtkPointGaussianVS =
"//VTK::System::Dec\n"
"\n"
"/*=========================================================================\n"
"\n"
"  Program:   Visualization Toolkit\n"
"  Module:    vtkPointGaussianVS.glsl\n"
"\n"
"  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen\n"
"  All rights reserved.\n"
"  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.\n"
"\n"
"     This software is distributed WITHOUT ANY WARRANTY; without even\n"
"     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR\n"
"     PURPOSE.  See the above copyright notice for more information.\n"
"\n"
"=========================================================================*/\n"
"// this shader implements imposters in OpenGL for Spheres\n"
"\n"
"attribute vec4 vertexMC;\n"
"attribute vec2 offsetMC;\n"
"\n"
"// optional normal declaration\n"
"//VTK::Normal::Dec\n"
"\n"
"// Texture coordinates\n"
"//VTK::TCoord::Dec\n"
"\n"
"// material property values\n"
"//VTK::Color::Dec\n"
"\n"
"// clipping plane vars\n"
"//VTK::Clip::Dec\n"
"\n"
"// camera and actor matrix values\n"
"//VTK::Camera::Dec\n"
"\n"
"varying vec2 offsetVCVSOutput;\n"
"uniform int cameraParallel;\n"
"\n"
"uniform float triangleScale;\n"
"\n"
"void main()\n"
"{\n"
"  //VTK::Color::Impl\n"
"\n"
"  //VTK::Normal::Impl\n"
"\n"
"  //VTK::TCoord::Impl\n"
"\n"
"  //VTK::Clip::Impl\n"
"\n"
"  // compute the projected vertex position\n"
"  vec4 vertexVC = MCVCMatrix * vertexMC;\n"
"\n"
"  // the offsets sent down are positioned\n"
"  // at 2.0*radius*triangleScale from the center of the\n"
"  // gaussian.  This has to be consistent\n"
"  // with the offsets we build into the VBO\n"
"  float radius = 0.5*sqrt(dot(offsetMC,offsetMC))/triangleScale;\n"
"\n"
"  // make the triangle face the camera\n"
"  if (cameraParallel == 0)\n"
"    {\n"
"    vec3 dir = normalize(-vertexVC.xyz);\n"
"    vec3 base2 = normalize(cross(dir,vec3(1.0,0.0,0.0)));\n"
"    vec3 base1 = cross(base2,dir);\n"
"    vertexVC.xyz = vertexVC.xyz + offsetMC.x*base1 + offsetMC.y*base2;\n"
"    }\n"
"  else\n"
"    {\n"
"    // add in the offset\n"
"    vertexVC.xy = vertexVC.xy + offsetMC;\n"
"    }\n"
"\n"
"  offsetVCVSOutput = offsetMC/radius;\n"
"  gl_Position = VCDCMatrix * vertexVC;\n"
"}\n"
"\n";

