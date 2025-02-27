// name: Record1
// status: correct
// cflags: -d=newInst -f

model Record1
  record R
    Real x;
    Real y;
    final constant Integer n = 3;
  end R;

  R r1(x(start = 1)=1, y(start = 2));
  R r2(x(start = 3), y(start = 4));
equation
  r1 = R(0,0);
  r2 = R(0,0);
end Record1;

// Result:
// model 'Record1'
// record 'R'
//   Real 'x';
//   Real 'y';
//   final constant Integer 'n' = 3;
// end 'R';
//
//   'R' 'r1';
//   'R' 'r2';
// equation
//   'r1' = 'Record1.R'(0.0, 0.0, 3);
//   'r2' = 'Record1.R'(0.0, 0.0, 3);
// end 'Record1';
// endResult
