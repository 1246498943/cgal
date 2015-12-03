// Copyright (c) 2007  GeometryFactory (France).  All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 3 of the License,
// or (at your option) any later version.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
// 
//
// Author(s)     : Andreas Fabri, Philipp Moeller

#ifndef CGAL_BOOST_GRAPH_TRAITS_SEAM_MESH_H
#define CGAL_BOOST_GRAPH_TRAITS_SEAM_MESH_H

#include <boost/graph/graph_traits.hpp>
#include <boost/graph/properties.hpp>

#include <boost/iterator/transform_iterator.hpp>

#include <CGAL/boost/graph/properties_Seam_mesh.h>
#include <CGAL/boost/graph/iterator.h>

#include <CGAL/boost/graph/Seam_mesh.h>
#include <CGAL/assertions.h>

namespace CGAL {

template <class TM>
class Seam_mesh;
}

namespace boost {

template <class P>
struct graph_traits< CGAL::Seam_mesh<P> >
{
private:
  typedef CGAL::Seam_mesh<P> SM;

  struct SM_graph_traversal_category : public virtual boost::bidirectional_graph_tag,
                                       public virtual boost::vertex_list_graph_tag,
                                       public virtual boost::edge_list_graph_tag
  {};

public:
  // Graph
  typedef typename SM::vertex_descriptor              vertex_descriptor;
  /*
  typedef typename SM::Point                                               vertex_property_type;
  */

  typedef typename SM::edge_descriptor  edge_descriptor;

  typedef boost::undirected_tag                                            directed_category;
  typedef boost::disallow_parallel_edge_tag                                edge_parallel_category; 
  typedef SM_graph_traversal_category                                      traversal_category;

  // HalfedgeGraph
  typedef typename SM::halfedge_descriptor            halfedge_descriptor;
  
   // FaceGraph
  typedef typename SM::face_descriptor   face_descriptor;
  
  // VertexListGraph
  typedef typename SM::vertex_iterator   vertex_iterator;
  typedef typename boost::graph_traits<P>::vertices_size_type vertices_size_type;
 
 // EdgeListGraph
  //typedef typename SM::edge_iterator  edge_iterator;
  
  //typedef typename SM::size_type              edges_size_type;
  // HalfEdgeListGraph
  //typedef typename SM::Halfedge_iterator halfedge_iterator;
  //typedef typename SM::size_type              halfedges_size_type;
  // FaceListGraph
  typedef typename boost::graph_traits<P>::face_iterator    face_iterator;
  //typedef typename SM::size_type              faces_size_type;

  // IncidenceGraph
  //typedef typename SM::size_type              degree_size_type;

  
  //typedef CGAL::In_edge_iterator<SM> in_edge_iterator;

  //typedef CGAL::Out_edge_iterator<SM> out_edge_iterator;

  // nulls
  static vertex_descriptor   null_vertex() { return vertex_descriptor(); }
  static face_descriptor     null_face() { return face_descriptor(); }
  static halfedge_descriptor null_halfedge() { return halfedge_descriptor(); }
};

template<typename P>
struct graph_traits< const CGAL::Seam_mesh<P> >  
  : public graph_traits< CGAL::Seam_mesh<P> >
{ };

} // namespace boost

namespace CGAL {


template <typename P>
typename boost::graph_traits<CGAL::Seam_mesh<P> >::vertices_size_type
num_vertices(const CGAL::Seam_mesh<P>& sm)
{
  return sm.m_num_vertices();
}

#if 0  

template <typename P>
typename boost::graph_traits<CGAL::Seam_mesh<P> >::edges_size_type
num_edges(const CGAL::Seam_mesh<P>& sm)
{
  return sm.m_num_edges();
}
  

template <typename P>
typename boost::graph_traits<CGAL::Seam_mesh<P> >::degree_size_type
degree(typename boost::graph_traits<CGAL::Seam_mesh<P> >::vertex_descriptor v,
       const CGAL::Seam_mesh<P>& sm)
{
  return sm.m_degree(v);
}

         
template <typename P>
typename boost::graph_traits<CGAL::Seam_mesh<P> >::degree_size_type
out_degree(typename boost::graph_traits<CGAL::Seam_mesh<P> >::vertex_descriptor v,
           const CGAL::Seam_mesh<P>& sm)
{
  return sm.m_degree(v);
}
             
  
template <typename P>
typename boost::graph_traits<CGAL::Seam_mesh<P> >::degree_size_type
in_degree(typename boost::graph_traits<CGAL::Seam_mesh<P> >::vertex_descriptor v,
          const CGAL::Seam_mesh<P>& sm)
{
  return sm.m_degree(v);
}
            
  
template <typename P>
typename boost::graph_traits<CGAL::Seam_mesh<P> >::vertex_descriptor
source(typename boost::graph_traits<CGAL::Seam_mesh<P> >::edge_descriptor e,
       const CGAL::Seam_mesh<P>& sm)
{
  return sm.m_source(e.halfedge());
}
#endif


template <typename P>
typename boost::graph_traits<CGAL::Seam_mesh<P> >::vertex_descriptor
source(typename boost::graph_traits<CGAL::Seam_mesh<P> >::halfedge_descriptor h,
       const CGAL::Seam_mesh<P>& sm)
{
  return sm.m_source(h);
}

#if 0
template <typename P>
typename boost::graph_traits<CGAL::Seam_mesh<P> >::vertex_descriptor
target(typename boost::graph_traits<CGAL::Seam_mesh<P> >::edge_descriptor e,
       const CGAL::Seam_mesh<P>& sm)
{
  return sm.m_target(e.halfedge());
}

#endif


template <typename P>
typename boost::graph_traits<CGAL::Seam_mesh<P> >::vertex_descriptor
target(typename boost::graph_traits<CGAL::Seam_mesh<P> >::halfedge_descriptor h,
       const CGAL::Seam_mesh<P>& sm)
{
  return sm.m_target(h);
}
    
template <typename P>
Iterator_range<typename boost::graph_traits<CGAL::Seam_mesh<P> >::vertex_iterator>
vertices(const CGAL::Seam_mesh<P>& sm)
{
  return sm.m_vertices(); 
}

 
#if 0
template <typename P>
Iterator_range<typename boost::graph_traits<CGAL::Seam_mesh<P> >::edge_iterator>
edges(const CGAL::Seam_mesh<P>& sm)
{
  return sm.edges(); 
}


template <typename P>
Iterator_range<typename boost::graph_traits<CGAL::Seam_mesh<P> >::in_edge_iterator>
in_edges(typename boost::graph_traits<CGAL::Seam_mesh<P> >::vertex_descriptor v,
         const CGAL::Seam_mesh<P>& sm)
{
  typedef typename boost::graph_traits<CGAL::Seam_mesh<P> >::in_edge_iterator Iter;

  return make_range(Iter(halfedge(v,sm),sm), Iter(halfedge(v,sm),sm,1));
}


template <typename P>
Iterator_range<typename boost::graph_traits<CGAL::Seam_mesh<P> >::out_edge_iterator>
out_edges(typename boost::graph_traits<CGAL::Seam_mesh<P> >::vertex_descriptor v,
          const CGAL::Seam_mesh<P>& sm)
{
  typedef typename boost::graph_traits<CGAL::Seam_mesh<P> >::out_edge_iterator Iter;
  return make_range(Iter(halfedge(v,sm),sm), Iter(halfedge(v,sm),sm,1));
}


template<typename P>
std::pair<typename boost::graph_traits<CGAL::Seam_mesh<P> >::edge_descriptor,
          bool>
edge(typename boost::graph_traits<CGAL::Seam_mesh<P> >::vertex_descriptor u, 
     typename boost::graph_traits<CGAL::Seam_mesh<P> >::vertex_descriptor v, 
     const CGAL::Seam_mesh<P>& sm) {
  typename boost::graph_traits<CGAL::Seam_mesh<P> >::edge_descriptor 
    he(sm.halfedge(u, v));
  return std::make_pair(he, he.is_valid());
}

#endif

//
// HalfedgeGraph
//
template <typename P>
typename boost::graph_traits<CGAL::Seam_mesh<P> >::halfedge_descriptor
next(typename boost::graph_traits<CGAL::Seam_mesh<P> >::halfedge_descriptor h,
     const CGAL::Seam_mesh<P>& sm)
{
  return sm.m_next(h);
}


template <typename P>
typename boost::graph_traits<CGAL::Seam_mesh<P> >::halfedge_descriptor
prev(typename boost::graph_traits<CGAL::Seam_mesh<P> >::halfedge_descriptor h,
     const CGAL::Seam_mesh<P>& sm)
{
  return sm.m_prev(h);
}


template <typename P>
typename boost::graph_traits<CGAL::Seam_mesh<P> >::halfedge_descriptor
opposite(typename boost::graph_traits<CGAL::Seam_mesh<P> >::halfedge_descriptor h,
         const CGAL::Seam_mesh<P>& sm)
{
  return sm.m_opposite(h);
}


template <typename P>
typename boost::graph_traits<CGAL::Seam_mesh<P> >::edge_descriptor
edge(typename boost::graph_traits<CGAL::Seam_mesh<P> >::halfedge_descriptor h,
     const CGAL::Seam_mesh<P>& sm)
{
  return h;
}

template <typename P>
typename boost::graph_traits<CGAL::Seam_mesh<P> >::halfedge_descriptor
halfedge(typename boost::graph_traits<CGAL::Seam_mesh<P> >::edge_descriptor e,
         const CGAL::Seam_mesh<P>& sm)
{
  return e.hd;
}



template <typename P>
typename boost::graph_traits<CGAL::Seam_mesh<P> >::halfedge_descriptor
halfedge(typename boost::graph_traits<CGAL::Seam_mesh<P> >::vertex_descriptor v,
         const CGAL::Seam_mesh<P>& sm)
{
  return halfedge_descriptor(boost::graph_traits<P>::halfedge_descriptor(v));
}


#if 0

template <typename P>
std::pair<
  typename boost::graph_traits<CGAL::Seam_mesh<P> >::halfedge_descriptor,
  bool
>
halfedge(typename boost::graph_traits<CGAL::Seam_mesh<P> >::vertex_descriptor u,
         typename boost::graph_traits<CGAL::Seam_mesh<P> >::vertex_descriptor v,
         const CGAL::Seam_mesh<P>& sm)
{
  typename boost::graph_traits<CGAL::Seam_mesh<P> >::halfedge_descriptor h = sm.halfedge(u, v);
  return std::make_pair(h, h.is_valid());
}



//
// HalfedgeListGraph
//
template <typename P>
Iterator_range<typename boost::graph_traits<CGAL::Seam_mesh<P> >::halfedge_iterator>
halfedges(const CGAL::Seam_mesh<P>& sm)
{
  return sm.halfedges();
}


template <typename P>
typename boost::graph_traits<CGAL::Seam_mesh<P> >::halfedges_size_type
num_halfedges(const CGAL::Seam_mesh<P>& sm)
{
  return sm.num_halfedges();
}




#endif

//
// FaceGraph
//
template<typename P>
typename boost::graph_traits<CGAL::Seam_mesh<P> >::halfedge_descriptor
halfedge(typename boost::graph_traits<CGAL::Seam_mesh<P> >::face_descriptor f,
     const CGAL::Seam_mesh<P>& sm) 
{
  return halfedge(f, sm.mesh());
}
  

template<typename P>
typename boost::graph_traits<CGAL::Seam_mesh<P> >::face_descriptor
face(typename boost::graph_traits<CGAL::Seam_mesh<P> >::halfedge_descriptor h,
     const CGAL::Seam_mesh<P>& sm) 
{
  if(h.seam){
    return boost::graph_traits<CGAL::Seam_mesh<P> >::null_face();
  }
  return face(h, sm.mesh());
}

 
//
// FaceListGraph
//
template <typename P>
typename boost::graph_traits<CGAL::Seam_mesh<P> >::faces_size_type
num_faces(const CGAL::Seam_mesh<P>& sm)
{
  return sm.num_faces();
}
  
template <typename P>
Iterator_range<typename boost::graph_traits<CGAL::Seam_mesh<P> >::face_iterator>
faces(const CGAL::Seam_mesh<P>& sm)
{
  return faces(sm.mesh()); 
}
 


} // namespace CGAL





#endif // CGAL_BOOST_GRAPH_TRAITS_SEAM_MESH_H
