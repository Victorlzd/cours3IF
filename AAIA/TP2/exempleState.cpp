#include <iostream>

#include <vector>
#include <set>
#include <queue>
#include <map>
#include <utility>
#include <list>
#include <functional>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <limits>
#include <chrono>

using namespace std;
#include "state.cpp"

//void addNeighbor
typedef pair<int,int> Move;



Move reverseMove(Move move)
{
    Move reverse;
    reverse.first = move.second;
    reverse.second = move.first;
    return reverse;
}

void addNeighbor( State &currentState, Move &move, 
             vector< pair< Move,int > > &neighbors,
             list<State>& path)
{
  currentState.doMove(move);
  if( find( path.begin(), path.end(), currentState ) == path.end() )
  {
    neighbors.push_back( make_pair( move, currentState.heuristic(2) ) );
  }
  currentState.doMove(reverseMove(move));
}

void generateNeighbors(State& currentState, vector< pair< Move,int > >& neighbors, list<State>& path)
{
    int i,j;
  for (i = 0; i < currentState.getNbStacks(); ++i)
  {
    if(!currentState.emptyStack(i))
    {
      for (j = 0; j < currentState.getNbStacks(); ++j)
      {
          if(j!=i)
          {
            Move move = make_pair(i,j);
            addNeighbor(currentState, move, neighbors, path);
          }
      }
    }
  }
}

void
search( State& currentState,
        int          ub, // upper bound over which exploration must stop
        int&         nub,
        list<State>& path,
        list<State>& bestPath,
        int&         nbVisitedState )

{
  nbVisitedState++;

  int f; // under-estimation of optimal length
  int g = path.size() - 1; // size of the current path to currentState

  if( currentState.isFinal() )
  {
    bestPath = path;
    return;
  }

  // generate the neighbors
  int s = currentState.heuristic(2);
  vector< pair< Move,int > > neighbors;
  neighbors.clear();
  

  generateNeighbors(currentState, neighbors, path);
  

  // sort the neighbors by heuristic value

  sort( neighbors.begin(), neighbors.end(),
      [](const pair<Move,int> &left, const pair<Move,int> &right) 
      {
        return left.second < right.second;
      } );


  for( const pair<Move,int> &p : neighbors )
  {
    f = g + 1 + p.second;
    if( f > ub )
    {
      if( f < nub )
      {
        nub = f; // update the next upper bound
      }
    }
    else
    {
      currentState.doMove(p.first );
      path.push_back( currentState );
      search( currentState, ub, nub, path, bestPath, nbVisitedState );
      path.pop_back();
      currentState.doMove( reverseMove(p.first ));
      if( !bestPath.empty() ) return;
    }
  }
}

void
ida( State&        initialState,
     list<State>&  bestPath, // path from source to destination
     int&          nbVisitedState )
{
  int ub;                      // current upper bound
  int nub = initialState.heuristic(2); // next upper bound
  list<State> path;
  path.push_back( initialState ); // the path to the target starts with the source

  while( bestPath.empty() && nub != numeric_limits<int>::max() )
  {
    ub = nub;
    nub = numeric_limits<int>::max();

    cout << "upper bound: " << ub;
    search( initialState, ub, nub, path, bestPath, nbVisitedState );
    cout << " ; nbVisitedState: " << nbVisitedState << endl;
  }
}




int main(){
    /*int nbStacks = 3;
    int nbBlocs = 4;n
    State state = State(nbBlocs,nbStacks);
    state.setInitial();
    cout << "Initial state s0:" << endl;
    state.display();
    state.doMove(make_pair(2,1));
    cout << "State s1 = t(s0,2->1) :" << endl;
    state.display();
    state.doMove(make_pair(0,2));
    cout << "State s2 = t(s1,0->2) :" << endl;
    state.display();
    state.doMove(make_pair(1,2));
    cout << "State s3 = t(s2,1->2) :" << endl;
    state.display();
    state.doMove(make_pair(1,2));
    cout << "State s4 = t(s3,1->2) :" << endl;
    state.display();
    state.doMove(make_pair(0,2));
    cout << "State s5 = t(s4,0->2) :" << endl;
    state.display();
    if (state.isFinal()){
        cout << "s5 is a final state..." << endl;
    }*/

    /*int nbStacks = 3;
    int nbBlocs = 4;
    State state = State(nbBlocs,nbStacks);
    state.setInitial();
    cout << "Initial state s0:" << endl;
    state.display();
    Move move = make_pair(2,1);
    state.doMove(move);
    cout << "State s1 = t(s0,2->1) :" << endl;
    state.display();
    state.doMove(reverseMove(move));
    cout << "return to state s0 :" << endl;
    state.display();*/

    int nbStacks = 3;
    int nbBlocs = 8;
    State state = State(nbBlocs,nbStacks);
    state.setInitial();
    list<State> path;
    path.clear();
    int nbVisitedState;

    /*state.display();
    cout << endl;

    vector< pair< Move,int > > neighbors;
    neighbors.clear();

    generateNeighbors(state, neighbors, path);*/

    ida(state, path, nbVisitedState);

    for( State st : path )
    {
        st.display();
        cout<<endl;
    }

    return 0;
}