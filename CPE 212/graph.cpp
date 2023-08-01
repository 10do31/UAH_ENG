/* graph.cpp - Project 6
Dan Otieno
Fall 2020 */


#include "graph.h"


  Graph::Graph()
  {
  	vertices = NULL;
  }									
  // Graph()
  // Constructor initializes vertices linked list to empty
	
  Graph::~Graph()
  {
  	VertexNode *temp = vertices;
    VertexNode *removetemp = temp;
    EdgeNode *temp2 = vertices->edgePtr;
    EdgeNode *removetemp2 = temp->edgePtr;

    while(temp != NULL) 
	{
      if(temp->edgePtr != NULL)
	  {
        temp2 = temp->edgePtr->nextPtr;

        while (temp2 != NULL) 
		{
          removetemp2 = temp2;
          temp2 = temp2->nextPtr;
          delete removetemp2;
        }
      }

      removetemp = temp;
      temp = temp->nextVertex;
      delete removetemp;
    }
  }
  // ~Graph()
  // For each VertexNode in the vertices list, Destructor deallocates all EdgeNodes before
  // deallocating the VertexNode itself
	
  void Graph::AddVertex(string v)
  {
    if(vertices == NULL)
    {
      vertices = new VertexNode;
      vertices->vname = v;
      vertices->nextVertex = NULL;
      vertices->edgePtr = NULL;
      vertices->mark = false;
    }

    else
    {
      VertexNode* temp = new VertexNode;
      temp->nextVertex = vertices;
      vertices = temp;
      vertices->edgePtr = NULL;
      vertices->vname = v;
      vertices->mark = false;
    }	
  }
  // AddVertex()
  // Adds vertex to graph assuming vertex not already present

  void Graph::AddEdge(string s, string d, int w)
  {
    try
    {
      EdgeNode* temp = new EdgeNode;
      delete temp;
    }

    catch(bad_alloc)
    {  
      throw GraphFull();
    }
  
    VertexNode *tempS = WhereIs(s);
    VertexNode *tempD = WhereIs(d);

    if(WhereIs(s) == NULL || WhereIs(d) == NULL)
    {
      throw GraphVertexNotFound();
    }

    VertexNode* v = WhereIs(s);
    
    if(v->edgePtr == NULL)
    { 
      v->edgePtr = new EdgeNode;
      v->edgePtr->destination = WhereIs(d);
      v->edgePtr->weight = w;
      v->edgePtr->nextPtr = NULL;
    }

    else
    {
      EdgeNode* temp = new EdgeNode;
      temp->destination = WhereIs(d);
      temp->weight = w;
      temp->nextPtr = v->edgePtr;
      v->edgePtr = temp;
    }
  }
  // AddEdge()
  // Adds edge from source S  to destination D with specified weight W.
  // If there is not enough memory to add the edge, throw the GraphFull exception
	
  bool Graph::IsPresent(string v)
  {
  	return WhereIs(v);
  }
  // IsPresent()
  // Returns true if vertex V in graph, false otherwise
	
  VertexNode*  Graph::WhereIs(string v)
  {
  	VertexNode* temp = vertices;

    while(temp->vname != v)
    {
      if(temp->nextVertex != NULL)
      {
        temp = temp->nextVertex;
      }
  
      else
      {
        return NULL;
      }
  
    }
    
    return temp;
  }
  /* Note: This function replaces IndexIs */
  // WhereIs()
  // Returns pointer to the vertex node that stores vertex v in the vertices linked list{ 
  // Throws GraphVertexNotFound if V is not present in the vertices list
	
  int  Graph::WeightIs(string s, string d)
  {
	if(WhereIs(s) == NULL || WhereIs(d) == NULL)
    {
      throw GraphVertexNotFound();
    }
    
    EdgeNode* temp = WhereIs(s)->edgePtr;
  
    while(temp->destination->vname != d)
    {
      if(temp->nextPtr != NULL)
      {
        temp = temp->nextPtr;
      }
    
      else
      {
        throw GraphEdgeNotFound();
      }
    }
  
    return temp->weight; 
  }
  // WeightIs()
  // Returns weight of edge (s,d).  Throws GraphEdgeNotFound if edge not present.
	
  void Graph::ClearMarks()
  {
  	VertexNode* temp = vertices;

    temp->mark = false;
  
    while(temp->nextVertex != NULL)
    {
      temp = temp->nextVertex;
      temp->mark = false;
    }
  }
  // ClearMarks()
  // Clears all vertex marks
	
  void Graph::MarkVertex(string v)
  {
  	if(WhereIs(v) == NULL)
    {
      throw GraphVertexNotFound();
    }
  
    WhereIs(v)->mark = true;
  }
  // MarkVertex()
  // Marks vertex V as visited
	
  bool Graph::IsMarked(string v)
  {
  	if(WhereIs(v) != NULL)
    {
      return WhereIs(v)->mark;
    }

    else
    {
      throw GraphVertexNotFound();
    }
  }
  // IsMarked()
  // Returns true if vertex V is marked, false otherwise

  void Graph::GetToVertices(string V, queue<string>& q)
  {
    if(WhereIs(V) == NULL)
    {
      throw GraphVertexNotFound();
    }

    EdgeNode* temp = WhereIs(V)->edgePtr;

    while(temp != NULL)
    {
      if(temp->destination->mark == false)
      {
        q.push(temp->destination->vname);
      }
    
      temp = temp->nextPtr;
    }
  }
  // GetToVertices()
  // Returns queue Q of vertex names of those vertices adjacent to vertex V
  // The queue here is from the Standard Template Library
	
  void Graph::DepthFirstSearch(string startVertex, string endVertex, queue<string>& path)
  {
  	if(WhereIs(startVertex) == NULL || WhereIs(endVertex) == NULL)
    {
      throw GraphVertexNotFound();
    }
  
    queue <string> q;
    stack <string> s;
  
    bool found = false;
    string vertex;
    string item;

    ClearMarks();
    s.push(startVertex);
  
    do
    {
      vertex = s.top();
      s.pop();
      if(vertex == endVertex)
      {
        path.push(vertex);
        found = true;
      }
    
      else
      {
        if(!IsMarked(vertex))
        {
          MarkVertex(vertex);
          path.push(vertex);
          GetToVertices(vertex, q);

          while(!q.empty())
          {
            item = q.front();
            q.pop();
            if(!IsMarked(item))
            {
              s.push(item);
            }
          }
        }
      }  
  
    } while (!s.empty() && !found);

    if(!found)
    {
      while(!path.empty())
      {
        path.pop();
      }
    }
  }
  // DepthFirstSearch()
  // Uses the DFS algorithm from the CPE 212 textbook to determine a path from the
  // startVertex to the endVertex.  If a path is found, the path vertices should
  // be in the path queue.  If no path is found, the path queue should be emptied
  // as a signal to the client code that no path exists between the start and
  // end vertices.
  //
  // Notes:
  // (1) This algorithm is flawed in that as it searches for a path, it may
  // output some additional vertices that it visited but were not part
  // of the actual path.  Implement the algorithm just as it appears in the textbook.
  // 
  // (2) This algorithm requires use of the stack and queue containers from the
  // Standard Template Library.  The STL stack and queue interfaces may require
  // minor modifications to the DFS code from the textbook.
