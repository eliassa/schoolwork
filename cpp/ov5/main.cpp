
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class ChessBoard {
public:
  enum class Color { WHITE,
                     BLACK };
  
  class Piece {
  public:
    Piece(Color color) : color(color) {}
    virtual ~Piece() {}

    Color color;
    std::string color_string() const {
      if (color == Color::WHITE)
        return "white";
      else
        return "black";
      
    }
    
    virtual string skriv_ut()const = 0;
    
    /// Return color and type of the chess piece
    virtual std::string type() const = 0;

    /// Returns true if the given chess piece move is valid
    virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
  };

  class King : public Piece {

  private:
     // Burde kanskje hatt den i piece?
  public:
    string name;
    King (Color color) : Piece(color),name("King"){}
    virtual ~King() {}

    std::string type() const override{
       return "Type: "+ name + ", Color: " + color_string();
     }
     
     bool valid_move(int from_x, int from_y, int to_x, int to_y) const override{

       double dist = sqrt(pow((from_x-to_x),2)+pow((from_y-to_y),2));
       return ((from_x-to_x<=1) && (from_y-to_y<=1)&&dist <=sqrt(2));
       
       
     }
     string skriv_ut() const override {
       return " "+color_string().substr(0,1)+name.substr(0,2)+" ";
     }
     
    
  };

  class Knight : public Piece {
    // missing implementations
    private:
      string name;
    public:
      Knight (Color color) : Piece(color),name("Knight"){}
      virtual ~Knight() {}
      
      std::string type() const override{
        return "Type: "+ name + ", Color: " + color_string();
      }
          
      bool valid_move(int from_x, int from_y, int to_x, int to_y) const override{

        double dist = sqrt(pow((from_x-to_x),2)+pow((from_y-to_y),2));
        return (((abs(from_x-to_x)==2) ||  abs(from_y-to_y)==2) && dist == sqrt(5));
      }
      
     string skriv_ut() const override {
       return " "+color_string().substr(0,1)+name.substr(0,2)+" ";
     }
  };

  ChessBoard() {
    // Initialize the squares stored in 8 columns and 8 rows:
    squares.resize(8);
    for (auto &square_column : squares)
      square_column.resize(8);
    
    
  }


  /// 8x8 squares occupied by 1 or 0 chess pieces
  vector<vector<unique_ptr<Piece>>> squares;
    
    void skriv_ut ()const{
         string res = "_________________________________________________________________________________";
         char bok = 'A';
         for (const auto & inner:squares){
           res +="\n";
           res+=bok++;
           res+=+"|";
              for (const auto & brikke:inner){
                if ( brikke == nullptr){
                  res+= "    0    \t";
                }
                else {
                  res+=brikke->skriv_ut()+"    \t";
                }
              }
           res +="|\n"; 
           }
           res += "_________________________________________________________________________________\n";
           res += "\t1\t    2\t\t    3\t\t    4\t\t    5\t\t    6\t\t    7\t\t    8   \n";
           cout << res;
       }

  /// Move a chess piece if it is a valid move
  bool move_piece(const std::string &from, const std::string &to) {
    int from_x = from.at(0) - 'a';
    int from_y = stoi(string() + from.at(1)) - 1;
    int to_x = to.at(0) - 'a';
    int to_y = stoi(string() + to.at(1)) - 1;

    auto &piece = squares.at(from_x).at(from_y);
    if (piece) {
      if (piece->valid_move(from_x, from_y, to_x, to_y)) {
        cout << piece->type() << " is moving from " << from << " to " << to << endl;
        auto &piece_at_to_pos = squares.at(to_x).at(to_y);
        if (piece_at_to_pos) {
          if (piece->color != piece_at_to_pos->color) {
            cout << piece_at_to_pos->type() << " is being removed from " << to << endl;
            
            if (auto king = dynamic_cast<King *>(piece_at_to_pos.get()))
              cout << king->color_string() << " lost the game" << endl;
          } else {
            // piece in the from square has the same color as the piece in the to square
            cout << "can not move " << piece->type() << " from " << from << " to " << to << endl;
            return false;
          }
        }
        piece_at_to_pos = move(piece);
        skriv_ut();
        return true;
      } else {
        cout << "can not move " << piece->type() << " from " << from << " to " << to << endl;
        return false;
      }
    } else {
      cout << "no piece at " << from << endl;
      return false;
    }
  }
  

};

int main() {
  ChessBoard board;

  //board.squares.at(4).at(0) is the same as board.squares[4][0] but with range check
  board.squares.at(4).at(0) = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
  board.squares.at(1).at(0) = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
  board.squares.at(6).at(0) = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

  board.squares.at(4).at(7) = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
  board.squares.at(1).at(7) = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
  board.squares.at(6).at(7) = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

  cout << "Invalid moves:" << endl;
  board.move_piece("e3", "e2");
  board.move_piece("e1", "e3");
  board.move_piece("b1", "b2");
  cout << endl;

  cout << "A simulated game:" << endl;
  board.skriv_ut();
  
  board.move_piece("e1", "e2");
  board.move_piece("g8", "h6");
  board.move_piece("b1", "c3");
  board.move_piece("h6", "g8");
  board.move_piece("c3", "d5");
  board.move_piece("g8", "h6");
  board.move_piece("d5", "f6");
  board.move_piece("h6", "g8");
  board.move_piece("f6", "e8");
}
