.. _changes_1_0_0:

Version 1.0.0 (2022-03-21)
--------------------------

Enhancements
~~~~~~~~~~~~

- Add ``use_orig_time`` option to :meth:`mne.Annotations.crop`. (:gh:`10396` by :newcontrib:`Michiru Kaneda`)

- Speed up :func:`mne.preprocessing.annotate_muscle_zscore`, :func:`mne.preprocessing.annotate_movement`, and :func:`mne.preprocessing.annotate_nan` through better annotation creation (:gh:`10089` by :newcontrib:`Senwen Deng`)

- Fix some unused variables in time_frequency_erds.py example (:gh:`10076` by :newcontrib:`Jan Zerfowski`)

- Document ``BAD_ACQ_SKIP`` annotation behavior (:gh:`10054` by :newcontrib:`Etienne de Montalivet`)

- Add link to related ``MNE-ARI`` package (:gh:`10174` by :newcontrib:`John Veillette`)

- :func:`mne.time_frequency.psd_array_multitaper` can now return complex results per-taper when specifying ``output='complex'`` (:gh:`10307` by `Mikołaj Magnuski`_)

- :func:`mne.time_frequency.tfr_array_multitaper` can now return results for ``output='phase'`` instead of an error (:gh:`10281` by `Mikołaj Magnuski`_)

- Add show local maxima toggling button to ``mne.gui.locate_ieeg`` (:gh:`9952` by `Alex Rockhill`_)

- Show boundaries in ``mne.gui.locate_ieeg`` (:gh:`10379` by `Eric Larson`_)

- Add argument ``cval`` to :func:`mne.transforms.apply_volume_registration` to set interpolation values outside the image domain (:gh:`10379` by `Eric Larson`_)

- Improve docstring of :class:`mne.Info` and add attributes that were not covered (:gh:`9922` by `Mathieu Scheltienne`_)

- Add an alternate, manual procedure for aligning a CT to an MR procedure to :ref:`tut-ieeg-localize` (:gh:`9978` by `Alex Rockhill`_)

- Improve docstring of export functions :func:`mne.export.export_raw`, :func:`mne.export.export_epochs`, :func:`mne.export.export_evokeds`, :func:`mne.export.export_evokeds_mff` and issue a warning when there are unapplied projectors (:gh:`9994` by `Mathieu Scheltienne`_)

- Add support for reading haemoglobin fNIRS data to :func:`mne.io.read_raw_snirf` (:gh:`9929` by `Robert Luke`_)

- Add ``fill_hole_size`` keyword argument to :func:`mne.viz.Brain.add_volume_labels` to close holes in the mesh (:gh:`10024` by `Alex Rockhill`_)

- Changed :class:`mne.Epochs` and :class:`mne.Evoked` to have a more concise ``__repr__`` to improve interactive MNE usage in Python Interactive Console, IDEs, and debuggers when many events are handled. (:gh:`10042` by `Jan Sosulski`_)

- Improve docstring of ``events`` arguments and cross-referencing to :term:`events` (:gh:`10056` by `Mathieu Scheltienne`_)

- Speed up repeated surface-smoothing operation (e.g., in repeated calls to :meth:`stc.plot() <mne.SourceEstimate.plot>`) (:gh:`10077` by `Eric Larson`_)

- Add ``verbose`` parameter to :func:`mne.io.Raw.load_bad_channels` and log information on how bad channels are updated (:gh:`10102` by `Stefan Appelhoff`_)

- Add ``infer_type`` argument to :func:`mne.io.read_raw_edf` and :func:`mne.io.read_raw_bdf` to automatically infer channel types from channel labels (:gh:`10058` by `Clemens Brunner`_)

- Reduce the time it takes to generate a :class:`mne.io.Raw`, :class:`~mne.Epochs`, or :class:`~mne.preprocessing.ICA` figure if a ``scalings`` parameter is provided (:gh:`10109` by `Richard Höchenberger`_ and `Eric Larson`_)

- :meth:`mne.Report.add_raw` gained a new ``scalings`` parameter to provide custom data scalings for the butterfly plots (:gh:`10109` by `Richard Höchenberger`_)

- The ``butterfly`` parameter of :meth:`mne.Report.add_raw` now also accepts numbers to specify how many segments to plot (:gh:`10115` by `Richard Höchenberger`_)

- The ``psd`` parameter of :meth:`mne.Report.add_epochs` now also accepts numbers to specify the signal duration used for PSD calculation (:gh:`10119` by `Richard Höchenberger`_)

- Drastically speed up butterfly plot generation in :meth:`mne.Report.add_raw`. We now don't plot annotations anymore; however, we feel that the speed improvements justify this change, also considering the annotations were of limited use in the displayed one-second time slices anyway (:gh:`10114`, :gh:`10116` by `Richard Höchenberger`_)

- In :class:`mne.Report`, limit the width of automatically generated figures to a maximum of 850 pixels (450 pixels for :class:`mne.SourceEstimate` plots), and the resolution to 100 DPI to reduce file size, memory consumption, and – in some cases like :meth:`mne.Report.add_stc` – processing time (:gh:`10126`, :gh:`10129`, :gh:`10135`, :gh:`10142` by `Richard Höchenberger`_)

- :class:`~mne.Epochs` metadata tables are now included in :class:`mne.Report` (:gh:`10166` by `Richard Höchenberger`_)

- :func:`mne.get_head_surf` and :func:`mne.dig_mri_distances` gained a new parameter, ``on_defects``, controlling how to handle surfaces with topological defects (:gh:`10175` by `Richard Höchenberger`_)

- :meth:`mne.Report.add_epochs` gained a new parameter, ``drop_log_ignore``, to control which drop reasons to omit when creating the drop log plot (:gh:`10182` by `Richard Höchenberger`_)

- :meth:`mne.Epochs.plot_drop_log` now also includes the absolute number of epochs dropped in the title (:gh:`10186` by `Richard Höchenberger`_)

- Add a button to show the maximum intensity projection in ``mne.gui.locate_ieeg`` (:gh:`10185` by `Alex Rockhill`_)

- Annotations from a :class:`~mne.io.Raw` object are now preserved by the :class:`~mne.Epochs` constructor and are supported when saving Epochs (:gh:`9969` and :gh:`10019` by `Adam Li`_)

- Add a checkbox to show and hide the MEG helmet in the coregistration GUI (:gh:`10200` by `Guillaume Favelier`_)

- The coregistration GUI (instantiated via :func:`mne.gui.coregistration`) gained a new attribute, ``coreg``, to access the :class:`mne.coreg.Coregistration` instance used by the GUI (:gh:`10255` by `Richard Höchenberger`_)

- Add marching cubes display of head if :func:`mne.bem.make_scalp_surfaces` has not computed or the recon-all hasn't finished (:gh:`10202` by `Alex Rockhill`_)

- The default interaction style of :func:`mne.gui.coregistration` and :func:`mne.viz.plot_alignment` has been changed to ``'terrain'``, which keeps one axis fixed and should make interactions with the 3D scene more predictable (:gh:`9972`, :gh:`10206` by `Richard Höchenberger`_)

- :func:`mne.gui.coregistration` now uses the proper widget style for push buttons, making for a more native feel of the application (:gh:`10220` by `Richard Höchenberger`_ and `Guillaume Favelier`_)

- :class:`mne.coreg.Coregistration`, :func:`mne.scale_bem`, and :func:`mne.scale_mri` gained a new parameter, ``on_defects``, controlling how to handle topological defects (:gh:`10230`, :gh:`10249` by `Richard Höchenberger`_)

- :class:`mne.coreg.Coregistration` gained a new attribute, ``fiducials``, allowing for convenient retrieval of the MRI fiducial points (:gh:`10243`, by `Richard Höchenberger`_)

- Added plotting points to represent contacts on the max intensity projection plot for ``mne.gui.locate_ieeg`` (:gh:`10212` by `Alex Rockhill`_)

- Add lines in 3D and on the maximum intensity projection when more than two electrode contacts are selected to aid in identifying that contact for ``mne.gui.locate_ieeg`` (:gh:`10212` by `Alex Rockhill`_)

- Add a ``block`` parameter to :class:`mne.viz.Brain` and the UI of :class:`mne.coreg.Coregistration` to prevent the windows from closing immediately when running in a non-interactive Python session (:gh:`10222` by `Guillaume Favelier`_)

- All methods of :class:`mne.Report` with a ``tags`` parameter now also accept a single tag passed as a string (previously, you needed to pass a tuple of strings, even for a single tag) (:gh:`10183`, by `Richard Höchenberger`_)

- :meth:`mne.Report.add_trans` has gained a new parameter, ``alpha``, to control the level of opacity of the rendered head (:gh:`10247`, by `Richard Höchenberger`_)

- The new convenience function :func:`mne.event.match_event_names` allows for straightforward checking if a specific event name or a group of events is present in a collection of event names (:gh:`10233` by `Richard Höchenberger`_)

- :meth:`Epochs.plot` is now supported by the pyqtgraph-backend (:gh:`10297` by `Martin Schulz`_)

- The ``map_surface`` parameter of :meth:`mne.viz.Brain.add_foci` now works and allows you to add foci to a rendering of a brain that are positioned at the vertex of the mesh closest to the given coordinates (:gh:`10299` by `Marijn van Vliet`_)

- :meth:`mne.preprocessing.ICA.plot_sources()` is now also supported by the ``qt`` backend (:gh:`10330` by `Martin Schulz`_)

- Added :meth:`mne.viz.Brain.add_dipole` and :meth:`mne.viz.Brain.add_forward` to plot dipoles on a brain as well as :meth:`mne.viz.Brain.remove_dipole` and :meth:`mne.viz.Brain.remove_forward` (:gh:`10373` by `Alex Rockhill`_)

- Made anterior/posterior slice scrolling in ``mne.gui.locate_ieeg`` possible for users without page up and page down buttons by allowing angle bracket buttons to be used (:gh:`10384` by `Alex Rockhill`_)

- Add support for ``theme='auto'`` for automatic dark-mode support in :meth:`raw.plot() <mne.io.Raw.plot>` and related functions and methods when using the ``'qt'`` backend (:gh:`10417` by `Eric Larson`_)

- Add support for ``MNE_3D_OPTION_THEME`` and ``MNE_BROWSER_THEME`` to use ``['light', 'dark', 'auto']`` or a custom  theme path in :class:`mne.viz.Brain` and :meth:`raw.plot() <mne.io.Raw.plot>` (and related functions and methods when using the ``'qt'`` backend(), respectively (:gh:`10418` by `Eric Larson`_)

- Add support for passing time-frequency data to :func:`mne.stats.spatio_temporal_cluster_test` and :func:`mne.stats.spatio_temporal_cluster_1samp_test` and added an example to :ref:`tut-cluster-spatiotemporal-sensor` (:gh:`10384` by `Alex Rockhill`_)

- Add support for reading optical density fNIRS data to :func:`mne.io.read_raw_snirf` (:gh:`10408` by `Robert Luke`_)

- Added :func:`mne.source_space.get_decimated_surfaces` to extract subsurfaces from a SourceSpaces instance or a .fif file (:gh:`10421` by `Joshua Teves`_)

Bugs
~~~~
- Fix bug with :func:`mne.io.read_raw_nihon` where latin-1 channels could not be read (:gh:`10429` by :newcontrib:`Matthias Eberlein`)

- Fix bug with :func:`mne.io.read_raw_nihon` so that it handles duplicates in channel names (:gh:`10431` by :newcontrib:`Matthias Eberlein`)

- Fix bug in :func:`mne.io.read_raw_egi` where the ``meas_date`` in a ``rawMFF`` object was incorrectly assigned. The function now converts the ``meas_date`` to UTC and provides a UTC offset key, i.e. ``raw.info['utc_offset']``. (:gh:`10304` by :newcontrib:`Scott Huberty`)

- Fix datetime conversion for tmin/tmax=None cases in :meth:`mne.Annotations.crop`. Allow the use of float and None simultaneously for :meth:`mne.Annotations.crop`. (:gh:`10361` by :newcontrib:`Michiru Kaneda`)

- Add Shift_JIST mu in :func:`mne.io.read_raw_edf` (:gh:`10356` by :newcontrib:`Michiru Kaneda`)

- Teach :func:`mne.io.read_raw_bti` to use its ``eog_ch`` parameter (:gh:`10093` by :newcontrib:`Adina Wagner`)

- Fix use of arguments in :func:`numpy.loadtxt` (:gh:`10189` by :newcontrib:`Federico Zamberlan`)

- Fix documentation of options in :func:`mne.stc_near_sensors` (:gh:`` by :newcontrib:`Nikolai Chapochnikov`)

- :func:`mne.time_frequency.tfr_array_multitaper` now returns results per taper when ``output='complex'`` (:gh:`10281` by `Mikołaj Magnuski`_)

- Fix default of :func:`mne.io.Raw.plot` to be ``use_opengl=None``, which will act like False unless ``MNE_BROWSER_USE_OPENGL=true`` is set in the user configuration (:gh:`9957` by `Eric Larson`_)

- Fix bug with :class:`mne.Report` where figures were saved with ``bbox_inches='tight'``, which led to inconsistent sizes in sliders (:gh:`9966` by `Eric Larson`_)

- When opening a saved report and saving it to a different filename again, don't change ``Report.fname`` to avoid a regression when using :func:`~mne.open_report` as a context manager (:gh:`9998` by `Marijn van Vliet`_)

- Fix bug in :func:`mne.make_forward_solution` where sensor-sphere geometry check was incorrect (:gh:`9968` by `Eric Larson`_)

- Use single char alphanumeric suffix when renaming long channel names (over 15-characters) when writing to FIF format. (:gh:`10002` by `Luke Bloy`_)

- Add argument ``overwrite`` to :func:`mne.export.export_raw`, :func:`mne.export.export_epochs`, :func:`mne.export.export_evokeds` and :func:`mne.export.export_evokeds_mff` (:gh:`9975` by `Mathieu Scheltienne`_)

- :func:`mne.gui.coregistration` and the ``mne coreg`` command didn't respect the ``interaction`` parameter (:gh:`9972` by `Richard Höchenberger`_)

- Fix incorrect projection of source space onto white matter surface instead of pial in :ref:`tut-working-with-ecog` (:gh:`9980` by `Alex Rockhill`_)

- Fix channel type support when reading from EEGLAB ``.set`` format with :func:`mne.io.read_raw_eeglab` and :func:`mne.read_epochs_eeglab` (:gh:`9990` by `Mathieu Scheltienne`_)

- Fix suboptimal alignment using :func:`mne.transforms.compute_volume_registration` (:gh:`9991` by `Alex Rockhill`_)

- Only warn if header is missing in BrainVision files instead of raising an error (:gh:`10001` by `Clemens Brunner`_)

- Add argument ``overwrite`` to `mne.preprocessing.ICA.save` to check for existing file (:gh:`10004` by `Mathieu Scheltienne`_)

- :class:`mne.Report` now raises an exception if invalid tags were passed (:gh:`9970` by `Richard Höchenberger`_)

- Fix bug in :func:`mne.get_montage_volume_labels` that set the maximum number of voxels to be included too low causing unwanted capping of the included voxel labels (:gh:`10021` by `Alex Rockhill`_)

- Fix annotation cropping and I/O roundtrip when there is no measurement date available (:gh:`10040` by `Mathieu Scheltienne`_ and `Alex Gramfort`_).

- Fix bug where :meth:`raw.crop() <mne.io.Raw.crop>` from the beginning of the instance could break annotations and ``raw.first_samp`` (:gh:`10358` by `Eric Larson`_)

- :func:`~mne.sys_info` output now contains the installed version of ``pooch``, too; this output had been accidentally removed previously (:gh:`10047` by `Richard Höchenberger`_)

- Fix VTK version extraction in :func:`mne.sys_info` (:gh:`10399` by `Eric Larson`_)

- Fix automatic channel type detection from channel labels in :func:`mne.io.read_raw_edf` and :func:`mne.io.read_raw_bdf` (and disable this functionality from :func:`mne.io.read_raw_gdf`) (:gh:`10058` by `Clemens Brunner`_)

- Fix :func:`~mne.stats.permutation_cluster_1samp_test` to properly handle 2-dimensional data in combination with TFCE (:gh:`10073` by `Richard Höchenberger`_)

- Fix channel grouping error when using "butterfly mode" with :meth:`mne.io.Raw.plot` (:gh:`10087` by `Daniel McCloy`_)

- Fix inconsistent behavior of ``mne.preprocessing.annotate_*`` functions by making them all return :class:`mne.Annotations` objects with the ``orig_time`` attribute set to ``raw.info["meas_time"]`` (:gh:`10067` and :gh:`10118` by `Stefan Appelhoff`_, `Eric Larson`_, and `Alex Gramfort`_)

- Fix bug that appears during automatic calculation of the colormap of `mne.viz.Brain` when data values of ``fmin`` and ``fmax`` are too close (:gh:`10074` by `Guillaume Favelier`_)

- We now display a scrollbar in the tags dropdown of a `~mne.Report` if many tags have been added, granting access to all tags instead of "hiding" them below the bottom of the page (:gh:`10082` by `Richard Höchenberger`_)

- Creating :class:`mne.Epochs` now provides clearer logging (less ambiguous, no duplicates) when the ``preload`` and/or ``metadata`` parameters are set (:gh:`10112` by `Stefan Appelhoff`_)

- Fix bug with :class:`mne.Epochs` where save-load round-trip with FIF would cause :meth:`mne.Epochs.apply_baseline` to no longer work (:gh:`10177` by `Eric Larson`_)

- Fix functions by adding missing ``overwrite`` parameters: :func:`mne.write_events`, :func:`mne.write_cov`, :func:`mne.write_evokeds`, :meth:`mne.SourceEstimate.save`, :func:`mne.minimum_norm.write_inverse_operator`, :func:`mne.write_proj`, and related methods (:gh:`10127` by `Eric Larson`_)

- Fix bug with :func:`mne.transforms.compute_volume_registration` and :func:`mne.compute_source_morph` (volumetric) where the smoothing factors were not scaled based on ``zooms`` (:gh:`10132` by `Eric Larson`_)

- Remove repeated logging output when overwriting an existing `~mne.io.Raw` file (:gh:`10095` by `Richard Höchenberger`_ and `Stefan Appelhoff`_)

- In the plots generated by :meth:`mne.Report.add_stc`, we now only add 5 labels to the color bar to reduce the chance of overlap, which could previously cause the labels to become unreadable (:gh:`10135` by `Richard Höchenberger`_)

- :meth:`mne.Report.add_trans` now allows you to add sensor alignment plots for head surfaces that have topological defects (:gh:`10175` by `Richard Höchenberger`_)

- :meth:`mne.Report.add_trans` now also works if no digitization points are present in the data (:gh:`10176` by `Jeff Stout`_)

- Argument ``verbose`` is now respected by dataset fetching (:gh:`10210` by `Mathieu Scheltienne`_)

- Fix bug with :func:`mne.io.read_raw_hitachi` where empty ``Comment`` descriptions were not handled properly (:gh:`10235` by `Eric Larson`_)

- Fix bug with input validation of low-level filtering functions (:gh:`10267` by `Eric Larson`_)

- :func:`mne.gui.coregistration` now works with surfaces containing topological defects (:gh:`10230`, by `Richard Höchenberger`_)

- Fix bug with :func:`mne.io.read_raw_nirx` being unable to read measurement dates recorded on systems with German (de_DE), French (fr_FR), and Italian (it_IT) locales (:gh:`10277` by `Eric Larson`_)

- Fix bug with projector normalization checks that were too sensitive, and improve warning (:gh:`10292` by `Eric Larson`_)

- Fix bug with :func:`mne.viz.plot_alignment` where head-coordinate source spaces (e.g., from a forward solution) were not properly plotted (:gh:`10309` by `Eric Larson`_)

- :func:`mne.read_trans` and :func:`mne.io.read_fiducials` now correctly expand ``~`` in the provided path (i.e., to the user's home directory) (:gh:`10265`, :gh:`10415`, by `Richard Höchenberger`_)

- :func:`mne.find_events` now uses ``first_samp`` and not ``0`` for initial event when using ``initial_value`` (:gh:`10289`, by `Alex Gramfort`_)

- Fix bug with :func:`mne.channels.make_standard_montage` for ``'standard*'``, ``'mgh*'``, and ``'artinis*'`` montages where the points were incorrectly scaled and fiducials incorrectly set away from the correct values for use with the ``fsaverage`` subject (:gh:`10324` by `Eric Larson`_)

- Fix bug with :meth:`mne.Report.add_figure` where figures generated externally were closed and possibly resized during render (:gh:`10342` by `Eric Larson`_)

- Fix bug with :func:`mne.viz.plot_sparse_source_estimates` where the return value was incorrect (:gh:`10347` by `Eric Larson`_)

- Fix plotting bug in :ref:`ex-electrode-pos-2d` and make view look more natural in :ref:`ex-movement-detect` (:gh:`10313`, by `Alex Rockhill`_)

- Fix bug with blank 3D rendering with MESA software rendering (:gh:`10400` by `Eric Larson`_)

- Fix a bug in ``mne.gui.locate_ieeg`` where 2D lines on slice plots failed to update and were shown when not in maximum projection mode (:gh:`10335`, by `Alex Rockhill`_)

- Fix misleading color scale in :ref:`tut-cluster-tfr` for the plotting of cluster F-statistics (:gh:`10393` by `Alex Rockhill`_)

- Fix baseline removal using ``remove_dc=True`` in :meth:`raw.plot() <mne.io.Raw.plot>` for data containing ``np.nan`` (:gh:`10392` by `Clemens Brunner`_)

- Fix misleading color scale in :ref:`tut-timefreq-twoway-anova` for plotting F-stats (:gh:`10401` by `Alex Rockhill`_)

- Fix misleading ``T_obs`` return name for :func:`mne.stats.spatio_temporal_cluster_test` when the default returns an F-statistic (:gh:`10401` by `Alex Rockhill`_)

API changes
~~~~~~~~~~~
- The default browser for :meth:`raw.plot() <mne.io.Raw.plot>`, :meth:`epochs.plot() <mne.Epochs.plot>`, and :meth:`ica.plot_sources() <mne.preprocessing.ICA.plot_sources>` has been changed to the ``'qt'`` backend on systems where `mne_qt_browser <https://github.com/mne-tools/mne-qt-browser>`__ is installed. To change back to matplotlib within a session, you can use :func:`mne.viz.set_browser_backend('matplotlib') <mne.viz.set_browser_backend>`. To set it permanently on your system, you can use :func:`mne.set_config('MNE_BROWSER_BACKEND', 'matplotlib') <mne.set_config>` (:gh:`9960` by `Martin Schulz`_ and `Eric Larson`_)

- ``mne.Info.pick_channels`` has been deprecated. Use ``inst.pick_channels`` to pick channels from :class:`~mne.io.Raw`, :class:`~mne.Epochs`, and :class:`~mne.Evoked`. Use :func:`mne.pick_info` to pick channels from :class:`mne.Info` (:gh:`10039` by `Mathieu Scheltienne`_)

- All :func:`data_path <mne.datasets.sample.data_path>` functions now return :class:`python:pathlib.Path` objects rather than strings. Support for string concatenation with plus (``+``) is thus deprecated and will be removed in 1.2, use the forward-slash ``/`` operator instead (:gh:`10348` by `Eric Larson`_)

- Argument ``event_list`` has been deprecated in favor of ``events`` in :func:`mne.write_events` (:gh:`10056` by `Mathieu Scheltienne`_)

- ``mne.preprocessing.annotate_flat`` has been deprecated in favor of :func:`mne.preprocessing.annotate_amplitude`, that covers both minimum and maximum peak-to-peak variation. (:gh:`10143` by `Mathieu Scheltienne`_)

- The ``max_ori_out`` parameter of :func:`mne.beamformer.apply_lcmv` and related functions is being removed as only signed estimates are supported. ``abs(stc)`` can be used to obtain unsigned estimates (:gh:`10366` by `Eric Larson`_)

- The ``verbose`` attribute of classes (e.g., :class:`mne.io.Raw`, `mne.Epochs`, etc.) has been deprecated. Explicitly pass ``verbose`` to methods as necessary instead. (:gh:`10267` by `Eric Larson`_)

- In :func:`mne.viz.set_browser_backend`, the `mne-qt-browser <https://github.com/mne-tools/mne-qt-browser>`__-based backend is now called ``'qt'`` rather than ``'pyqtgraph'`` for simplicity (:gh:`10323` by `Eric Larson`_)

Dependencies
~~~~~~~~~~~~
Numerous external dependencies that used to be bundled with MNE-Python are now
not shipped with the package anymore and will instead be retrieved
automatically from their official sources when you install MNE-Python. This
simplifies MNE-Python maintenance and keeps the package smaller. The following
new dependencies have been added:

- `Jinja2`_ (replaces ``Tempita``, which is not maintained anymore; :gh:`10211` by `Richard Höchenberger`_)


.. _Jinja2: https://jinja.palletsprojects.com/

Authors
~~~~~~~

* Adam Li
* Adina Wagner+
* Alex Rockhill
* Alexandre Gramfort
* Britta Westner
* Clemens Brunner
* Daniel McCloy
* Eduard Ort
* Eric Larson
* Etienne de Montalivet+
* Federico Zamberlan+
* Guillaume Favelier
* Jan Sosulski
* Jan Zerfowski+
* Jeff Stout
* John Veillette+
* Joshua Teves
* Julia Guiomar Niso Galán
* Luke Bloy
* Marijn van Vliet
* Martin Schulz
* Mathieu Scheltienne
* Matthias Eberlein+
* Michiru Kaneda+
* Mikołaj Magnuski
* Nikolai Chapochnikov+
* Richard Höchenberger
* Robert Luke
* Scott Huberty+
* Senwen Deng+
* Stefan Appelhoff
* Steve Matindi
* Thomas Hartmann
