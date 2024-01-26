-- theorem foo : A → A :=
--   fun x => x

-- example (h1 : A) (h2 : B) : A ∧ B :=
--   ⟨h1, h2⟩

-- example (h : A ∧ B) : A :=
--   match h with
--   | ⟨h1, _⟩ => h1

-- theorem deMorgan1 : (¬(A ∧ B) ↔ ¬A ∨ ¬B) :=
--   have ha := fun h => sorry

--   have hb := fun h h1 =>
--     match h with
--     | .inl h => h h1.1
--     | .inr h => h h1.2

--   ⟨ha, hb⟩

-- theorem deMorgan2 : (¬(A ∨ B) ↔ ¬A ∧ ¬B) :=
--   have ha := fun h =>
--     have a := fun h1 => h (.inl h1)
--     have b := fun h1 => h (.inr h1)
--     ⟨a, b⟩

--   have hb := fun ⟨h1, h⟩ h =>
--   match h with

--   ⟨ha, hb⟩

example : ¬(A ∨ B) ↔ ¬A ∧ ¬B :=
  have ha := sorry

  have hb := fun ⟨h1, h2⟩ h3 =>
    match h3 with
    | .inl h3 => h1 h3
    | .inr h3 => h2 h3

  ⟨ha, hb⟩
