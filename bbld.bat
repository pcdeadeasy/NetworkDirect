IF EXIST build (
    CD build
    cmake --build . --target %1
    CD ..
) ELSE (
    CALL bprep
    CD build
    cmake --build . --target %1
    CD ..
)
