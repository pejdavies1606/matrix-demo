/*
 * Matrix
 */
#include <iostream>
#include <stdexcept>

template <class T>
class Matrix;

template <class T>
std::istream& operator >> (
   std::istream& is,
   Matrix<T>& m);

template <class T>
std::ostream& operator << (
   std::ostream& os,
   const Matrix<T>& m);

template <class T>
class Matrix
{
   private:
      T* data;
      int rows, cols;
   public:
      Matrix(int rows, int cols);
      Matrix(const Matrix& m);
      ~Matrix();
      T findMax();

      /*
       * Array Subscript
       */
      T* operator[](int row)
      {
         return &this->data[row * this->cols];
      }

      /*
       * Assignment
       */
      Matrix& operator=(const Matrix &m)
      {
         if (&m != this) 
         {
            if (this->rows != m.rows ||
                this->cols != m.cols) 
            {
               delete []this->data;
               this->rows = m.rows;
               this->cols = m.cols;
               this->data = new T[this->rows * this->cols];
               if(!this->data)
               {
                  throw std::runtime_error(
                     "memory error");
               }
            }
            std::copy(
                  m.data,
                  m.data + (m.rows * m.cols),
                  this->data);
         }
         return *this;
      }

      /*
       * Stream Insertion
       */
      friend std::istream& operator >> (
            std::istream& is,
            Matrix<T>& m)
      {
         for (int i = 0; i < m.rows; i++)
         {
            for (int j = 0; j < m.cols; j++)
            {
               std::cout
                  << "[" << i
                  << "," << j
                  << "]" 
                  << "=";
               is >> m.data[i*m.cols + j];
            }
         }
         return is;
      }

      /*
       * Stream Extraction
       */
      friend std::ostream& operator << (
         std::ostream& os,
         const Matrix<T>& m)
      {
         for (int i = 0; i < m.rows; i++)
         {
            for (int j = 0; j < m.cols; j++)
            {
               os << "[" << i
                  << "," << j
                  << "]="
                  << m.data[i*m.cols + j]
                  << std::endl;
               // TODO pretty print
               // ( 0, 1)
               // (10,11)
               //if (j == 0)
               //{
               //   os << "(";
               //}
               //os << m.data[i*m.cols + j];
               //if (j < m.cols - 1)
               //{
               //   os << ",";
               //}
            }
            //os << ")" << std::endl;
         }
         return os;
      }
};

/*
 * Constructor
 */
template <class T>
Matrix<T> ::
Matrix(int rows, int cols)
{
   if (rows > 0 && cols > 0)
   {
      this->rows = rows;
      this->cols = cols;
      this->data = new T(rows * cols);
   }
   else
   {
      throw std::invalid_argument(
         "rows and cols must be positive");
   }
}

/*
 * Copy Constructor
 */
template <class T>
Matrix<T> ::
Matrix(const Matrix& m)
{
   if (m.rows > 0 &&
       m.cols > 0 &&
       m.data)
   {
      rows = m.rows;
      cols = m.cols;
      data = new T(rows * cols);
      std::copy(
         m.data,
         m.data + (m.rows * m.cols),
         data);
   }
}

/*
 * Destructor
 */
template <class T>
Matrix<T> ::
~Matrix()
{
   if (this->data)
   {
      this->rows = 0;
      this->cols = 0;
      delete(this->data);
   }
}

/*
 * findMax
 */
template <class T>
T Matrix<T> ::
findMax()
{
   int max_i = 0;
   int max_j = 0;
   T max = (T) 0;
   if (this->rows > 0 &&
       this->cols > 0 &&
       this->data)
   {
      for (int i = 0; i < this->rows; i++)
      {
         for (int j = 0; j < this->cols; j++)
         {
            T val = this->data[i*this->cols + j];
            if (val > max)
            {
               max = val;
               max_i = i;
               max_j = j;
            }
         }
      }
      std::cout << "["
         << max_i << "," 
         << max_j << "]="
         << max << " (max)"
         << std::endl;
   }
   return max;
}

