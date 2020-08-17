/*
 *  Copyright (c) 2020 Jeremy HU <jeremy-at-dust3d dot org>. All rights reserved. 
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:

 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.

 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */
#ifndef AUTO_REMESHER_MESH_CUTTER_H
#define AUTO_REMESHER_MESH_CUTTER_H
#include <AutoRemesher/Vector3>
#include <vector>

namespace AutoRemesher
{
    
class MeshCutter
{
public:
    MeshCutter(const std::vector<Vector3> &vertices,
            const std::vector<std::vector<size_t>> &triangles) :
        m_vertices(vertices),
        m_triangles(triangles)
    {
    }
    
    const std::vector<Vector3> &getFirstHalfVertices()
    {
        return m_firstHalfVertices;
    }
    
    const std::vector<Vector3> &getSecondHalfVertices()
    {
        return m_secondHalfVertices;
    }
    
    const std::vector<std::vector<size_t>> &getFirstHalfTriangles()
    {
        return m_firstHalfTriangles;
    }
    
    const std::vector<std::vector<size_t>> &getSecondHalfTriangles()
    {
        return m_secondHalfTriangles;
    }
    
    void cut();
private:
    std::vector<Vector3> m_vertices;
    std::vector<std::vector<size_t>> m_triangles;
    std::vector<Vector3> m_firstHalfVertices;
    std::vector<std::vector<size_t>> m_firstHalfTriangles;
    std::vector<Vector3> m_secondHalfVertices;
    std::vector<std::vector<size_t>> m_secondHalfTriangles;
};
    
}

#endif